int x,y; 
double z;

cout << "enter two ints and a double" << endl;
cin >> x >> y >> z;

while(cin.fail()) {
    cout << " one or more of the inputs was invalid please try again" << endl;
    cin >> x>>y>>>x;
}