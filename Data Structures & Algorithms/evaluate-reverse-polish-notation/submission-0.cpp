class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        int n = tokens.size();

        int ans = 0;

        int opr1 = 0;
        int opr2 = 0;

        for(int i=0; i<n; i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(tokens[i]);
            }
            else{
                if(tokens[i] == "+"){
                    ans = stoi(st.top());
                    st.pop();
                    ans += stoi(st.top());
                    st.pop();
                    st.push(to_string(ans));
                }
                if(tokens[i] == "*"){
                    ans = stoi(st.top());
                    st.pop();
                    ans *= stoi(st.top());
                    st.pop();
                    st.push(to_string(ans));
                }
                if(tokens[i] == "-"){
                    opr2 = stoi(st.top());
                    st.pop();
                    opr1 = stoi(st.top());
                    ans = opr1 - opr2;
                    st.pop();
                    st.push(to_string(ans));
                }
                if(tokens[i] == "/"){
                    opr2 = stoi(st.top());
                    st.pop();
                    opr1 = stoi(st.top());
                    ans = opr1 / opr2;
                    st.pop();
                    st.push(to_string(ans));
                }

            }
        }
        if(st.size() == 0){
            return ans;
        }
        else{
            return stoi(st.top());
        }
    }
};
