class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestX = std::max(x1, std::min(xCenter, x2));
        int closestY = std::max(y1, std::min(yCenter, y2));
        
        int distX = xCenter - closestX;
        int distY = yCenter - closestY;
        
        return (distX * distX + distY * distY) <= (radius * radius);
    }
};