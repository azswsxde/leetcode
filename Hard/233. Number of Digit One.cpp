class Solution
{
public:
    // '1' count under           9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999
    size_t onedigitCount[10]={1, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
    /*
     * format a stack
     * example:
     * 123 to 1
     *        2
     *        3
     */
    void setStack(std::stack<size_t>* digitsNumber, int number)
    {
        while (number >= 10)
        {
            digitsNumber->push((number % 10));
            number = number / 10;
        }
        digitsNumber->push(number);
    }
    int countDigitOne(int n)
    {
        int answer = 0;
        std::stack<size_t> digitsNumber;
        if (n == 0)
        {
            return 0;
        }
        // create stack first
        setStack(&digitsNumber, n);


        // according the stack size to add '1' count
        // example:
        // 123456 = 1*50000 + 23456 + 1 + 2*4000 + 10000 + 3*300 + 1000 + 4*20 + 100 + 5*1 + 10
        //                  1(23456)               23456           3456          456         56
        //                                      10000~19999      1000~1999     100~199      10~19
        for (int i = digitsNumber.size(); i > 0; i--)
        {
            size_t powerofTen = 0;
            if (digitsNumber.size() != 1)
            {
                answer += onedigitCount[i - 1] * digitsNumber.top();

                powerofTen = pow(10, digitsNumber.size() - 1);
                if (digitsNumber.top() > 1)
                {
                    answer += powerofTen;
                }
                else if (digitsNumber.top() == 1)
                {
                    answer += ((n % powerofTen) + 1);
                }
            }
            else
            {
                if (digitsNumber.top() > 0)
                {
                    answer += 1;
                }
            }
            digitsNumber.pop();
        }
        return answer;
    }
};