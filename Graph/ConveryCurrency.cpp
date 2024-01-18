#include<bits/stdc++.h>

using namespace std;

class Converter{
    public:
        virtual float findConversion(string source, string target) = 0;
};


class CurrenyConverter : public Converter {
    private:
        void traversal(unordered_set<string>& visitedCurrencies, string source, string target, vector<float> &maxConversion, float prod) {
        
            if(source == target) {
                maxConversion.push_back(prod);
                return;
            }

            for(auto neighbour : graph[source]) {
                if(visitedCurrencies.find(neighbour.first) == visitedCurrencies.end()) {
                    visitedCurrencies.insert(neighbour.first);
                    traversal(visitedCurrencies, neighbour.first, target, maxConversion, prod * neighbour.second);
                    visitedCurrencies.erase(neighbour.first);
                }
            }

        }

    public:
        unordered_map<string, vector<pair<string, float>>> graph;
        
        CurrenyConverter(vector<vector<string>> currencies) {
            createGraph(currencies);
        }

        float findConversion(string source, string target) {
            if(graph.find(source) == graph.end() || graph.find(target) == graph.end()) {
                cout << "Not Possible " << endl; 
                return -1;
            }
            unordered_set<string> visitedCurrencies;
            vector<float> maxConversion; 

            traversal(visitedCurrencies, source, target, maxConversion, 1);

            return *max_element(maxConversion.begin(), maxConversion.end());

        }

        

        void createGraph(vector<vector<string>> currencies) {
            for(auto row : currencies) {

                graph[row[0]].push_back({row[1], (float)stoi(row[2])});
                graph[row[1]].push_back({row[0], 1/(float)stoi(row[3])});
            }
        }
        
};


int main() {
    // buy and sell stocks
    // Currency Exchange https://leetcode.com/discuss/interview-question/1647092/Coinbase-or-Virtual-On-site-or-Interview-Questions
    // in-memory filesystem
    // 

    vector<vector<string>> currencies{
        {"USD", "BTC", "99", "100"}, 
        {"EUR", "BTC", "115", "120"},
        {"USD", "ETH", "98", "100"},
        {"EUR", "ETH", "400", "420"}
    };

    string source = "USD";
    string target = "EUR";

    CurrenyConverter* currencyConverter = new CurrenyConverter(currencies);
    cout << currencyConverter->findConversion(source, target);


}