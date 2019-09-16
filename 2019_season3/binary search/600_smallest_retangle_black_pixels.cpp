// Description
// English
// An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

// Have you met this question in a real interview?  
// Example
// Example 1:

// Input：["0010","0110","0100"]，x=0，y=2
// Output：6
// Explanation：
// The upper left coordinate of the matrix is (0,1), and the lower right coordinate is (2,2).
// Example 2:

// Input：["1110""1100""0000""0000"], x = 0, y = 1
// Output：6
// Explanation：
// The upper left coordinate of the matrix is (0, 0), and the lower right coordinate is (1,2).

class Solution {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(vector<vector<char>> &image, int x, int y) {
        //retange 
        //(minX,minY) , (maX, maxY)
        int m = image.size(); 
        if (m ==0) return 0;
        int n = image[0].size();
        if (n == 0) return 0;
        
        queue<pair<int,int>>q;
        q.push({x,y});
        image[x][y] = '0';
        
        int minX = INT_MAX; int maxX = INT_MIN;
        int minY = INT_MAX; int maxY = INT_MIN;
        
        int op1[]=  {1,-1,0,0};
        int op2[] = {0,0,1,-1};
        
        while (!q.empty()){
            auto p = q.front(); q.pop();
            
            //update the pos
            if (minX > p.first) minX = p.first;
            if (maxX < p.first) maxX = p.first;
            if (minY > p.second) minY = p.second;
            if (maxY < p.second) maxY = p.second;
            
            //push the next blac pixel   
            for(int c = 0; c < 4; c++){
                int tmpX = p.first + op1[c];
                int tmpY = p.second + op2[c];
                
                if (tmpX >=0 && tmpX < m && tmpY >=0 && tmpY <n && image[tmpX][tmpY] == '1'){
                    image[tmpX][tmpY] = '0';
                    q.push({tmpX,tmpY});
                }
            }
        }
        return (maxX -minX + 1) * (maxY - minY + 1);
    }
};