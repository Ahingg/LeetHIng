class Robot {
public:

    int w, h;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  

    int currDirIndex = 0;
    vector<int> pos;
    Robot(int width, int height) {
        w = width;
        h = height;
        pos.resize(2, 0);
    }

    int rotate() {
        int posX = pos[0], posY  = pos[1];
        if(currDirIndex == 0 || currDirIndex == 2) {
            if(posY == 0) return 1;
            if(posY == h - 1) return 3;
        }
        else {
            if(posX == 0) return 0;
            if(posX == w - 1) return 2;
        }
        return -1;
    }
    
    void step(int num) {
        int keliling = (2 * (w-1)) + (2*(h-1));
        num %= keliling;
        num += keliling;
        while(num) {
            int dirX = dir[currDirIndex][0];
            int dirY = dir[currDirIndex][1];
            int sx = dirX * num;
            int sy = dirY * num;

            // cout << "num, curr dir:" << num << " " <<  currDirIndex << endl;
            // cout << "Pos x, y:" << pos[0] << " " << pos[1] << endl;
            if(dirX) {
                int target = sx + pos[0];
                // cout << "Move X: " << target << endl;
                if(target >= w) {
                    target = w - 1;
                    num -= (w - pos[0] - 1); 
                    currDirIndex = rotate();
                }
                else if(target < 0) {
                    target = 0;
                    num -= pos[0];
                    currDirIndex = rotate();
                }
                else {
                    num = 0;
                }
                pos[0] = target;
                // cout << "end index, target: " << currDirIndex << " " << target << endl;
            }
            else {
                int target = sy + pos[1];
                // cout << "Move Y: " <<  target << endl;
                if(target >= h) {
                    target = h - 1;
                    num -= (h - pos[1] - 1);
                    currDirIndex = rotate();
                }
                else if(target < 0) {
                    target = 0;
                    num -= pos[1];
                    currDirIndex = rotate();
                }
                else {
                    num = 0;
                }
                pos[1] = target;
                // cout << "end index: " << currDirIndex << endl;
            }
            // cout << "end num: " << num << endl;
            // cout << endl;
        }
    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        switch(currDirIndex){
            case 1:
                return "North";
                break;
            case 0:
                return "East";
                break;
            case 3:
                return "South";
                break;
            case 2: 
                return "West";
                break;
            default: 
                return "";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */