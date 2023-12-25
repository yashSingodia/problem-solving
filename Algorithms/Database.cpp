#include<bits/stdc++.h>
using namespace std;

class Value {
    string value;
};

class Database {
    public:
        unordered_map<string, string> db;
        unordered_map<string, string> cache;
        vector<vector<string>> wal;
        bool insideTransaction;

        Database() {
            db = {};
            wal = {};
            insideTransaction = false;
        }

        unordered_map<string, string> currentNode() {

            if(insideTransaction) {
                return cache;
            }
            return db;
        }

        void setNode(unordered_map<string, string> node) {
            
            if(insideTransaction) {
                 cache = node;
            }
            db = node;
        }

        string create(string key, string val) {
            // cout << "create: " << key << " " << val << endl;
            unordered_map<string, string> curNode = currentNode();
            
            if(curNode.find(key) == curNode.end()) {
                curNode[key] = val;
                setNode(curNode);
                return val;
            }
            return update(key, val);
        }

        string read(string key) {
            unordered_map<string, string> curNode = currentNode();
            if(curNode.find(key) == curNode.end()) {
                return "No Key Found.";
            }
            return curNode[key];
        }

        string update(string key, string val) {
            unordered_map<string, string> curNode = currentNode();
            if(curNode.find(key) == curNode.end()) {
                return "No Key Found.";
            }
            // cout << "update: " << key << " " << val << endl;
            curNode[key] = val;
            setNode(curNode);
            return val;
        }

        string deleteKey(string key) {
            unordered_map<string, string> curNode = currentNode();
            if(curNode.find(key) == curNode.end()) {
                return "No Key Found.";
            }
            curNode.erase(key);
            setNode(curNode);
            return "Delete Success.";
        }

        void beginTransaction() {
            insideTransaction = true;
            cache = db;
            wal = {};
        }

        void commitTransaction(int numTransactions = 0) {
            if(numTransactions == 0)
                {
                    db = cache;
                    insideTransaction = false;
                }
            else {
                insideTransaction = false;
                retryWal(numTransactions);
            }
            wal = {};
            // insideTransaction = false;
        }

        void rollbackTransaction(int numTransactions = 0) {
            if(numTransactions == 0)
                {
                    cache = {};
                    insideTransaction = false;
            }
            else {
                insideTransaction = false;
                retryWal(wal.size() - numTransactions);
            }
            wal = {};
            // insideTransaction = false;
        }

        void retryWal(int retries) {
            for(int i = 0; i < retries; i++) {
                    cout << "retry: " << wal[i][0] << " " << wal[i][1] << " " << wal[i][2] << endl;
                    solve(wal[i], true);
            }
        }

        void solve(vector<string> q, bool isRetry = false) {
            string str;
            
            if(q[0] == "read") {

                str = read(q[1]);

            } else if(q[0] == "create") {
                
                if(!isRetry) {
                    wal.push_back(q);
                }
                
                str = create(q[1], q[2]);

            } else if(q[0] == "update") {
                
                if(!isRetry) {
                    wal.push_back(q);
                }
                str = update(q[1], q[2]);

            } else if(q[0] == "delete") {
                
                if(!isRetry) {
                    wal.push_back(q);
                }
                str = deleteKey(q[1]);

            } else if(q[0] == "begin") {

                beginTransaction();

            } else if(q[0] == "commit") {
                
                if(q.size() == 1)
                    commitTransaction();
                else {
                    commitTransaction(stoi(q[1]));
                }

            } else if(q[0] == "rollback") {

                if(q.size() == 1)
                    rollbackTransaction();
                else {
                    rollbackTransaction(stoi(q[1]));
                }

            }

            cout << str << endl;
            
        }
};

int main() {


    vector<vector<string>> input;
    // input.push_back({"read", "key1"});
    // input.push_back({"create", "key1", "val1"});
    // input.push_back({"read", "key1"});
    // input.push_back({"update", "key1", "val2"});
    // input.push_back({"delete", "key1"});
    // input.push_back({"read", "key1"});

    
    // input.push_back({"create", "key1", "val1"});
    // input.push_back({"create", "key2", "val2"});
    // input.push_back({"create", "key3", "val3"});
    // input.push_back({"read", "key1"});
    // input.push_back({"read", "key2"});
    // input.push_back({"read", "key3"});

    // input.push_back({"begin"});
    // input.push_back({"create", "key3", "val8"});
    // input.push_back({"read", "key3"});
    // input.push_back({"create", "key5", "val5"});
    // input.push_back({"read", "key5"});
    // input.push_back({"update", "key5", "val7"});
    // input.push_back({"read", "key5"});
    // input.push_back({"update", "key2", "val8"});
    // input.push_back({"read", "key2"});
    // input.push_back({"delete", "key1"});
    // input.push_back({"read", "key1"});
    // input.push_back({"commit"});

    // input.push_back({"read", "key1"});
    // input.push_back({"read", "key2"});
    // input.push_back({"read", "key3"});

    input.push_back({"create", "key1", "val1"});
    input.push_back({"create", "key2", "val2"});
    input.push_back({"create", "key3", "val3"});
    input.push_back({"read", "key1"});
    input.push_back({"read", "key2"});
    input.push_back({"read", "key3"});

    input.push_back({"begin"});
    input.push_back({"create", "key3", "val8"});
    input.push_back({"read", "key3"});
    input.push_back({"create", "key5", "val5"});
    input.push_back({"read", "key5"});
    input.push_back({"update", "key5", "val7"});
    input.push_back({"read", "key5"});
    input.push_back({"update", "key2", "val8"});
    input.push_back({"read", "key2"});
    input.push_back({"delete", "key1"});
    input.push_back({"read", "key1"});
    input.push_back({"commit", "2"});

    input.push_back({"read", "key1"});
    input.push_back({"read", "key2"});
    input.push_back({"read", "key3"});
    input.push_back({"read", "key5"});


    Database* database = new Database();

    for(int i = 0; i<input.size(); i++) {
        database->solve(input[i]);
    }
    return 0;

}