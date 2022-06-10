// Source Code:

bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> s;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char brd = board[i][j];
                if (brd != '.'){
                    string c = string(1,brd);
                    string row = c + " in row " + to_string(i);
                    string col = c + " in col " + to_string(j);
                    string block = c + " in block " + to_string(i/3) + "-" + to_string(j/3);
                    if(s.find(row) != s.end() || s.find(col) != s.end() || s.find(block) != s.end())
                        return false;

                    s.insert(row);
                    s.insert(col);
                    s.insert(block);
                }
            }
        }
        return true;
    }