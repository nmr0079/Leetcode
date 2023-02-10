class Solution {
public:
    void addValidPar(int n,int cl,int cr,string& vpar,vector<string>& out){
        //base case
        if(cl == n && cr == n){
            out.push_back(vpar);
            return;
        }
        
        if(cl < n){
            vpar = vpar.append("(");
            addValidPar(n,cl+1,cr,vpar,out);
            vpar = vpar.substr(0,vpar.size()-1);
        }
        
        if(cr < cl){
            vpar = vpar.append(")");
            addValidPar(n,cl,cr+1,vpar,out);
            vpar = vpar.substr(0,vpar.size()-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string vpar;
        addValidPar(n,0,0,vpar,out);
        return out;
    }
};