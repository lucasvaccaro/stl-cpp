//This is pasted into main.cpp at compile
//main.cpp has all the necessary #includes

const string KEY1 = "qweqwe";
const string KEY2 = "abc";
const string KEY3 = "HUEHUEHUEHUE";
const string KEY4 = "Murica!";
const string KEY5 = "cheese";

const int VAL1 = 2;
const int VAL2 = -5;
const int VAL3 = 5227;
const int VAL4 = 2000000000;
const int VAL5 = 2220;
const int VAL6 = 100;

string* randomInserts;
const int randomCount = 10000;
const int REPETITIONS = 500; 

clock_t t;
float timeMS;

void printTimeTests_SetArray(SetArray &adt);
void printTimeTests_SetLinkedList(SetLinkedList &adt);
void printTimeTests_HashSet(HashSet &adt);
void printTimeTests_MultiSetArray(MultiSetArray &adt);
void printTimeTests_MultiSetLinkedList(MultiSetLinkedList &adt);
void printTimeTests_HashMultiSet(HashMultiSet &adt);
void printTimeTests_MapArray(MapArray &adt);
void printTimeTests_MapLinkedList(MapLinkedList &adt);
void printTimeTests_HashMap(HashMap &adt);
void printTimeTests_MultiMapArray(MultiMapArray &adt);
void printTimeTests_MultiMapLinkedList(MultiMapLinkedList &adt);
void printTimeTests_HashMultiMap(HashMultiMap &adt);


//Returns a random string
string getRandoStr(int length){
    static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string retString = "";
    for(int y = 0; y < length; y++){
        retString += alphabet[rand()% (26*2) ];
    }
    return retString;
}

string* getRandoArray(int lengthOfArray, int wordLength){
	string* retArr = new string[lengthOfArray];
	for(int i =0; i < lengthOfArray; i++){
		retArr[i] = getRandoStr(wordLength);
	}
	return retArr;
}
void printTimeTests(){
	//compares how long things take with different DSes under the hood
    cout << "TIME TESTINGS: " << REPETITIONS << " reptitions within tests..."; 
	cout << endl << endl;
	
	randomInserts = getRandoArray(randomCount, 10);
	
	SetArray sa;
	SetLinkedList sll;
	HashSet hs;
	MultiSetArray msa;
	MultiSetLinkedList msll;
	HashMultiSet hms;
	MapArray ma;
	MapLinkedList mll;
	HashMap hm;
	MultiMapArray mma;
	MultiMapLinkedList mmll;
	HashMultiMap hmm;

	printTimeTests_SetArray(sa);
	printTimeTests_SetLinkedList(sll);
	printTimeTests_HashSet(hs);

	printTimeTests_MultiSetArray(msa);
	printTimeTests_MultiSetLinkedList(msll);
	printTimeTests_HashMultiSet(hms);
	
	printTimeTests_MapArray(ma);
	printTimeTests_MapLinkedList(mll);
	printTimeTests_HashMap(hm);

    printTimeTests_MultiMapArray(mma);
	printTimeTests_MultiMapLinkedList(mmll);
	printTimeTests_HashMultiMap(hmm);
}

void printTimeTests_SetArray(SetArray &sa) {
	//test Insert and Remove time
	cout << "SetArray -- Time to insert and remove 5 keys: ";
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		sa.insert(KEY1);
		sa.insert(KEY2);
		sa.insert(KEY3);
		sa.insert(KEY4);
		sa.insert(KEY5);
		sa.remove(KEY1);
		sa.remove(KEY2);
		sa.remove(KEY3);
		sa.remove(KEY4);
		sa.remove(KEY5);
	}

	//time in milliseconds
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Search time
	
	cout << "SetArray -- Time to complete 3 different key searches: ";
    
    
	sa.insert(KEY1);
	sa.insert(KEY2);
	sa.insert(KEY3);
	sa.insert(KEY4);
	sa.insert(KEY5);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		sa.is_in(KEY1);
		sa.is_in(KEY2);
		sa.is_in(KEY4);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		sa.insert(randomInserts[i]);
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	sa.is_in(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_SetLinkedList(SetLinkedList &sll) {
	cout << "SetLinkedList -- Time to insert and remove 5 keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		sll.insert(KEY1);
		sll.insert(KEY2);
		sll.insert(KEY3);
		sll.insert(KEY4);
		sll.insert(KEY5);
		sll.remove(KEY1);
		sll.remove(KEY2);
		sll.remove(KEY3);
		sll.remove(KEY4);
		sll.remove(KEY5);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	//test Search time
	cout << "SetLinkedList -- Time to complete 3 different key searches: ";

	sll.insert(KEY1);
	sll.insert(KEY2);
	sll.insert(KEY3);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		sll.is_in(KEY1);
		sll.is_in(KEY2);
		sll.is_in(KEY3);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		sll.insert(randomInserts[i]);
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	sll.is_in(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_HashSet(HashSet &sh) {
	//test Insert and Remove time
	cout << "HashSet -- Time to insert and remove 5 keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		sh.insert(KEY1);
		sh.insert(KEY2);
		sh.insert(KEY3);
		sh.insert(KEY4);
		sh.insert(KEY5);
		sh.remove(KEY1);
		sh.remove(KEY2);
		sh.remove(KEY3);
		sh.remove(KEY4);
		sh.remove(KEY5);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	//test Search time
	cout << "HashSet -- Time to complete 3 different key searches: ";

	sh.insert(KEY1);
	sh.insert(KEY2);
	sh.insert(KEY3);
	sh.insert(KEY4);
	sh.insert(KEY5);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		sh.is_in(KEY1);
		sh.is_in(KEY2);
		sh.is_in(KEY4);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount << " elements" << endl;
	for(int i = 0; i < randomCount; i++){
		sh.insert(randomInserts[i]);
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	sh.is_in(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

//----------------------MULTISET TESTING------------------------------------
void printTimeTests_MultiSetArray(MultiSetArray &msa) {	
	//test Insert and Remove time
	cout << "MultiSetArray -- Time to insert and remove 5 keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msa.insert(KEY1);
		msa.insert(KEY2);
		msa.insert(KEY3);
		msa.insert(KEY4);
		msa.insert(KEY5);
		msa.removeAll(KEY1);
		msa.removeAll(KEY2);
		msa.removeAll(KEY3);
		msa.removeAll(KEY4);
		msa.removeAll(KEY5);
	}

	//time in milliseconds
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	//test Search time
	cout << "MultiSetArray -- Time to complete 3 different key searches: ";

	msa.insert(KEY1);
	msa.insert(KEY2);
	msa.insert(KEY2);
	msa.insert(KEY3);
	msa.insert(KEY3);
	msa.insert(KEY3);
	msa.insert(KEY3);
	msa.insert(KEY4);
	msa.insert(KEY5);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msa.is_in(KEY1);
		msa.is_in(KEY2);
		msa.is_in(KEY4);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Count time
	cout << "MultiSetArray -- Time to count 3 different keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msa.count(KEY2);
		msa.count(KEY3);
		msa.count(KEY5);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		msa.insert(randomInserts[i]);
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	msa.is_in(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_MultiSetLinkedList(MultiSetLinkedList &msll) {
	//test Insert and Remove time
	cout << "MultiSetLinkedList -- Time to insert and remove 5 keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msll.insert(KEY1);
		msll.insert(KEY2);
		msll.insert(KEY3);
		msll.insert(KEY4);
		msll.insert(KEY5);
		msll.removeAll(KEY1);
		msll.removeAll(KEY2);
		msll.removeAll(KEY3);
		msll.removeAll(KEY4);
		msll.removeAll(KEY5);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Search time
	cout << "MultiSetLinkedList -- Time to complete 3 different key searches: ";
	
	msll.insert(KEY1);
	msll.insert(KEY2);
	msll.insert(KEY2);
	msll.insert(KEY3);
	msll.insert(KEY3);
	msll.insert(KEY3);
	msll.insert(KEY3);
	msll.insert(KEY4);
	msll.insert(KEY5);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msll.is_in(KEY1);
		msll.is_in(KEY2);
		msll.is_in(KEY4);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	//test Count time
	cout << "MultiSetLinkedList -- Time to count 3 different keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msll.count(KEY2);
		msll.count(KEY3);
		msll.count(KEY5);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		msll.insert(randomInserts[i]);
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	msll.is_in(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_HashMultiSet(HashMultiSet &msh) {
	//test Insert and Remove time
	cout << "HashMultiSet -- Time to insert and remove 5 keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msh.insert(KEY1);
		msh.insert(KEY2);
		msh.insert(KEY3);
		msh.insert(KEY4);
		msh.insert(KEY5);
		msh.removeAll(KEY1);
		msh.removeAll(KEY2);
		msh.removeAll(KEY3);
		msh.removeAll(KEY4);
		msh.removeAll(KEY5);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Search time
	cout << "HashMultiSet -- Time to complete 3 different key searches: ";

	msh.insert(KEY1);
	msh.insert(KEY2);
	msh.insert(KEY2);
	msh.insert(KEY3);
	msh.insert(KEY3);
	msh.insert(KEY3);
	msh.insert(KEY3);
	msh.insert(KEY4);
	msh.insert(KEY5);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msh.is_in(KEY1);
		msh.is_in(KEY2);
		msh.is_in(KEY4);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	//test Count time
	cout << "HashMultiSet -- Time to count 3 different keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		msh.count(KEY2);
		msh.count(KEY3);
		msh.count(KEY5);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		msh.insert(randomInserts[i]);
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	msh.is_in(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

//---------------------------MAP TESTING------------------------------------
void printTimeTests_MapArray(MapArray &ma) {	
	//test Insert and Remove time
	cout << "MapArray -- Time to set and remove 5 keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		ma.set(KEY1, VAL1);
		ma.set(KEY2, VAL2);
		ma.set(KEY3, VAL3);
		ma.set(KEY4, VAL4);
		ma.set(KEY5, VAL5);
		ma.remove(KEY1);
		ma.remove(KEY2);
		ma.remove(KEY3);
		ma.remove(KEY4);
		ma.remove(KEY5);
	}
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Search
	cout << "MapArray -- Time to retrieve 5 values: ";

	ma.set(KEY1, VAL1);
	ma.set(KEY2, VAL2);
	ma.set(KEY3, VAL3);
	ma.set(KEY4, VAL4);
	ma.set(KEY5, VAL5);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		ma.get(KEY1);
		ma.get(KEY2);
		ma.get(KEY3);
		ma.get(KEY4);
		ma.get(KEY5);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		ma.set(randomInserts[i], rand());
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	int myValue = ma.get(myRand);
	cout << "Value found: " << myValue << endl;
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_MapLinkedList(MapLinkedList &mll) {
	//test Insert and Remove time
	cout << "MapLinkedList -- Time to set and remove 5 keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mll.set(KEY1, VAL1);
		mll.set(KEY2, VAL2);
		mll.set(KEY3, VAL3);
		mll.set(KEY4, VAL4);
		mll.set(KEY5, VAL5);
		mll.remove(KEY1);
		mll.remove(KEY2);
		mll.remove(KEY3);
		mll.remove(KEY4);
		mll.remove(KEY5);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Search
	cout << "MapLinkedList -- Time to retrieve 5 values: ";

	mll.set(KEY1, VAL1);
	mll.set(KEY2, VAL2);
	mll.set(KEY3, VAL3);
	mll.set(KEY4, VAL4);
	mll.set(KEY5, VAL5);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mll.get(KEY1);
		mll.get(KEY2);
		mll.get(KEY3);
		mll.get(KEY4);
		mll.get(KEY5);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		mll.set(randomInserts[i], rand());
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	int myValue = mll.get(myRand);
	cout << "Value found: " << myValue << endl;
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_HashMap(HashMap &mh) {
	//test Insert and Remove time
	cout << "HashMap -- Time to set and remove 5 keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mh.set(KEY1, VAL1);
		mh.set(KEY2, VAL2);
		mh.set(KEY3, VAL3);
		mh.set(KEY4, VAL4);
		mh.set(KEY5, VAL5);
		mh.remove(KEY1);
		mh.remove(KEY2);
		mh.remove(KEY3);
		mh.remove(KEY4);
		mh.remove(KEY5);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Search
	cout << "HashMap -- Time to retrieve 5 values: ";

	mh.set(KEY1, VAL1);
	mh.set(KEY2, VAL2);
	mh.set(KEY3, VAL3);
	mh.set(KEY4, VAL4);
	mh.set(KEY5, VAL5);
	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mh.get(KEY1);
		mh.get(KEY2);
		mh.get(KEY3);
		mh.get(KEY4);
		mh.get(KEY5);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		mh.set(randomInserts[i], rand());
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	int myValue = mh.get(myRand);
	cout << "Value found: " << myValue << endl;
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_MultiMapArray(MultiMapArray &mma) {
	//test Insert and Remove time
	cout << "MultiMapArray -- Time to set and remove 5 keys/values: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mma.set(KEY1, VAL1);
		mma.set(KEY2, VAL2);
		mma.set(KEY3, VAL3);
		mma.set(KEY3, VAL4);
		mma.set(KEY3, VAL5);
		mma.removeAll(KEY1);
		mma.removeAll(KEY2);
		mma.removeAll(KEY3);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Search time
	cout << "MultiMapArray -- Time to get 3 keys and all their values: ";

	mma.set(KEY1, VAL1);
	mma.set(KEY2, VAL2);
	mma.set(KEY3, VAL3);
	mma.set(KEY3, VAL4);
	mma.set(KEY3, VAL5);
	mma.set(KEY4, VAL1);
	mma.set(KEY4, VAL2);
	mma.set(KEY5, VAL3);

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mma.getAll(KEY2);
		mma.getAll(KEY3);
		mma.getAll(KEY4);
	}
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Count time
	cout << "MultiMapArray -- Time to count values for 3 different keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mma.count(KEY2);
		mma.count(KEY3);
		mma.count(KEY5);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		mma.set(randomInserts[i], rand());
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	int* myValue = mma.getAll(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	int arrSize = (sizeof((myValue))/sizeof((myValue[0])));
	for(int i = 0; i < arrSize; i++){
		cout << myValue[i] << " |";
	}
	cout << endl;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_MultiMapLinkedList(MultiMapLinkedList &mmll) {
	//test Insert and Remove time
	cout << "MultiMapLinkedList -- Time to set and remove 5 keys/values: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mmll.set(KEY1, VAL1);
		mmll.set(KEY2, VAL2);
		mmll.set(KEY3, VAL3);
		mmll.set(KEY3, VAL4);
		mmll.set(KEY3, VAL5);
		mmll.removeAll(KEY1);
		mmll.removeAll(KEY2);
		mmll.removeAll(KEY3);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Search time
	cout << "MultiMapLinkedList -- Time to get 3 keys and all their values: ";

	mmll.set(KEY1, VAL1);
	mmll.set(KEY2, VAL2);
	mmll.set(KEY3, VAL3);
	mmll.set(KEY3, VAL4);
	mmll.set(KEY3, VAL5);
	mmll.set(KEY4, VAL1);
	mmll.set(KEY4, VAL2);
	mmll.set(KEY5, VAL3);

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mmll.getAll(KEY2);
		mmll.getAll(KEY3);
		mmll.getAll(KEY4);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Count time
	cout << "MultiMapLinkedList -- Time to count values for 3 different keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mmll.count(KEY2);
		mmll.count(KEY3);
		mmll.count(KEY5);
	}

	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		mmll.set(randomInserts[i], rand());
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	int* myValue = mmll.getAll(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	int arrSize = (sizeof((myValue))/sizeof((myValue[0])));
	for(int i = 0; i < arrSize; i++){
		cout << myValue[i] << " |";
	}
	cout << endl;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}

void printTimeTests_HashMultiMap(HashMultiMap &mmh) {
	//test Insert and Remove time
	cout << "HashMultiMap -- Time to set and remove 5 keys/values: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mmh.set(KEY1, VAL1);
		mmh.set(KEY2, VAL2);
		mmh.set(KEY3, VAL3);
		mmh.set(KEY3, VAL4);
		mmh.set(KEY3, VAL5);
		mmh.removeAll(KEY1);
		mmh.removeAll(KEY2);
		mmh.removeAll(KEY3);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;	

	//test Search time
	cout << "HashMultiMap -- Time to get 3 keys and all their values: ";

	mmh.set(KEY1, VAL1);
	mmh.set(KEY2, VAL2);
	mmh.set(KEY3, VAL3);
	mmh.set(KEY3, VAL4);
	mmh.set(KEY3, VAL5);
	mmh.set(KEY4, VAL1);
	mmh.set(KEY4, VAL2);
	mmh.set(KEY5, VAL3);

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mmh.getAll(KEY2);
		mmh.getAll(KEY3);
		mmh.getAll(KEY4);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;

	//test Count time
	cout << "HashMultiMap -- Time to count values for 3 different keys: ";

	t = clock();
	for (int i = 0; i < REPETITIONS; i++) {
		mmh.count(KEY2);
		mmh.count(KEY3);
		mmh.count(KEY5);
	}

	timeMS = ((float) (clock() - t) / CLOCKS_PER_SEC) * 1000;
	cout << timeMS << " milliseconds" << endl;
	
	cout << "Inserting a random array of " << randomCount <<" elements" << endl;
	for(int i = 0; i < randomCount; i++){
		mmh.set(randomInserts[i], rand());
	}
	cout << "Finding a random element in the array " << endl;
	string myRand = randomInserts[rand()%randomCount];
	cout << "Random element: " << myRand << endl;
	t = clock();
	int* myValue = mmh.getAll(myRand);
	timeMS = ((float)(clock() - t) / CLOCKS_PER_SEC) * 1000;
	int arrSize = (sizeof((myValue))/sizeof((myValue[0])));
	for(int i = 0; i < arrSize; i++){
		cout << myValue[i] << " |";
	}
	cout << endl;
	cout << "Time searching: " << timeMS << " milliseconds " << endl;
	cout << endl;
}