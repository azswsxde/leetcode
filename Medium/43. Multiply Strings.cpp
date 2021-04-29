#define MAX_LENGTH 110
class Solution
{
    public:
        void do_mulit(string multiplicand, string multiplier, short* container, string& result)
        {
            int container_index = MAX_LENGTH * 2 - 1, container_temp_index = MAX_LENGTH * 2 - 1;
            int temp = 0;
            int MULTIPLICAND_LENGTH = multiplicand.length();
            int MULTIPLIER_LENGTH = multiplier.length();
            for (int multiplicand_index = MULTIPLICAND_LENGTH - 1; multiplicand_index >= 0; multiplicand_index--)
            {
                for (int multiplier_index = MULTIPLIER_LENGTH - 1; multiplier_index >= 0; multiplier_index--)
                {
                    temp = (multiplicand[multiplicand_index] - '0') * (multiplier[multiplier_index] - '0');
                    container_temp_index = container_index - (MULTIPLICAND_LENGTH - 1 - multiplicand_index) - (MULTIPLIER_LENGTH - 1 - multiplier_index);
                    if (container[container_temp_index] == -1)
                    {
                        container[container_temp_index] = temp;
                    }
                    else
                    {
                        container[container_temp_index] += temp;
                    }
                }
            }

            int quotient = 0;
            while (container[container_index] != -1)
            {
                quotient = container[container_index] / 10;
                if (quotient > 0)
                {
                    if (container[container_index - 1] == -1)
                    {
                        container[container_index - 1] = quotient;
                    }
                    else
                    {
                        container[container_index - 1] += quotient;
                    }
                }
                container[container_index] = container[container_index] % 10;
                result = (char)(container[container_index] + '0') + result;
                container_index--;
            }
        }

        string multiply(string num1, string num2)
        {
            short container[MAX_LENGTH * 2];
            int container_index = MAX_LENGTH * 2 - 1;
            string result = "";
            for (int i = 0; i <= container_index; i++)
            {
                container[i] = -1;
            }
            
            if (num1 == "0" || num2 == "0")
            {
                return "0";
            }

            if (num1.length() > num2.length())
            {
                do_mulit(num1, num2, container, result);
            }
            else
            {
                do_mulit(num2, num1, container, result);
            }

            return result;
        }
};