class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        if (turnedOn > 8 || turnedOn < 0)
            return result;
        if (turnedOn == 0) {
            result.push_back("0:00");
            return result;
        }

        vector<vector<string>> min = {{"00"},{"01","02","04","08","16","32"},{"03","05","09","17","33","06","10","18","34","12","20","36","24","40","48"},{"07","11","19","35","13","21","37","25","41","49","14","22","38","26","42","50","28","44","56","52"},{"15","23","39","27","43","51","29","45","53","57","30","58","46","54"},{"31","47","55","59"}};
        vector<vector<string>> hour = {{"0:"},{"1:","2:","4:","8:"},{"3:","5:","9:","6:","10:"},{"7:","11:"}};
        unsigned short min_select , hour_select , i, j;

        for (min_select = 0; min_select <= 5; ++min_select) {
            if (min_select > turnedOn)
                continue;
            for (hour_select = 0; hour_select <= 3; ++hour_select) {
                if ((min_select + hour_select) > turnedOn) 
                    break;
                if (min_select + hour_select == turnedOn) {
                    for (i = 0; i < min[min_select].size(); i++) {
                        for (j = 0; j < hour[hour_select].size(); j++) {
                            result.push_back(hour[hour_select][j] + min[min_select][i]);
                        }
                    }
                }
            }
        }
        return result;
    }
};