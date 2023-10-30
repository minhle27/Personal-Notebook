/**
 * Description: Backtracking model
 */

const int maxn = 33;
int x[maxn];
int n;

void printRes(){
    for (int i = 1; i <= n; i++){
        cout << x[i];
    }
    cout << endl;
}

// find all binary string of length N
void backtrack(int i){
    for (int j = 0; j <= 1; j++){ // all values can be assigned to x[i] 
        x[i] = j; // try x[i] = j
        if (i == n) printRes(); // tim thay 1 cau hinh
        else backtrack(i + 1); // recursively try values for x[i + 1]
    }
}

// backtrack(1)

// Liet ke cac tap con k phan tu
void backtrack(int i){
    for (int j = x[i - 1] + 1; j <= n - k + i; j++){
        x[i] = j;
        if (i == k) printRes();
        else backtrack(i + 1);
    }
}

// Liet ke cac chinh hop ko lap chap k
void backtrack(int i){
    for (int j = 1; j <= n ;j++){
        if (c[j]){
            x[i] = j;
            if (i == k) printRes();
            else {
                c[j] = false;
                backtrack(i + 1);
                c[j] = true;
            }
        }
    }
}

