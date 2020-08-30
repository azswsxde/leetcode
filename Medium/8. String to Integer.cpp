class Solution {
public:
    int checkstr(string& s){
        string max = "2147483647"; // for char compare greater then INT_MAX or not
        bool might_overflow = false;
        int have_sign = 1; // for check is positive number or negative number
        int len = s.length();
        // check first char
        if (  s[0] != '-'
           && s[0] != '+'
           && (s[0] < '0' || s[0] > '9')
           )
        {
            return 0;
        }
        
        // if len less than 10, means keyword must smaller then INT_MAX or INT_MIN return atoi(keyword)
        if (len < 10){
            return atoi(s.c_str());
        }
        else
        {
            int index = 0; //char index
            int max_index = 0; //string max char index

            // for check first char sign
            if (s[index] == '-'){
                have_sign = -1;
                max = "2147483648"; // for char compare less then INT_MIN or not
                index++;
            }
            else if (s[index] == '+'){
                have_sign = 1;
                index++;
            }

            // add keyword char index. ex: keyword is 000189, parser index to '1' index
            if (s[index] == '0'){
                while (s[index + 1] == '0'){
                    index++;
                }
                index++;
            }

            // check max string char and parsered keyword char
            // compare s[index] and max[max_index]
            for(int i = index; i < len; i++){
                // max_index over max string length must over flow
                if (max_index > 10){
                    if (have_sign == -1){
                        return INT_MIN;
                    }
                    else{
                        return INT_MAX;
                    }
                    break;
                }

                if (s[i] > max[max_index]){
                    if (s[i] <= '9' && s[i] >= '0'){
                        might_overflow = true;
                    }
                    else
                    {
                        //string contain not 1 ~ 9 char, let atoi to check
                        return atoi(s.c_str());
                    }
                }
                else{
                    //string contain not 1 ~ 9 char, let atoi to check
                    if (s[i] > '9' || s[i] < '0'){
                        return atoi(s.c_str());
                    }
                
                }
                max_index++;
            }

            // +2147483647
            // 2147483674
            if (might_overflow && max_index >= 9){
                if (have_sign == -1){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }  
            }
            
            return atoi(s.c_str());
        }
    }
    
    int myAtoi(string str) {
        string keyword;
        size_t white_index = str.find(' ');
        size_t index = 0;
        // parser str for first string
        // if white_index == string::npos, means not white space pass str as keyword for checkstr
        // if white_index != 0, means we need to parser first substring as keyword for checkstr
        // if white_index == 0, 
        // means we need to find first not equal white space index and parser first substring as keyowrd for checkstr
        if (white_index == string::npos){
            keyword = str;
        }
        else if (white_index != 0){
            keyword = str.substr(index, white_index - index);
        }
        else{
            while (str[white_index + 1] == ' '){
                white_index++;
            }

            index = white_index + 1;
            white_index = str.find(' ', index);

            if (white_index != string::npos){
                keyword = str.substr(index, white_index - index);
            }
            else{
                keyword = str.substr(index);
            }
        }
        return checkstr(keyword);
    }
};