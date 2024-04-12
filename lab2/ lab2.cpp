#include <iostream>
#include <string>

using namespace std;

class ChessPiece 
{
private:
    string name;
    string color;
    string material; 
    string pos;  
    float size;      

public:
    ChessPiece(string pieceName, string pieceColor, string pieceMaterial, float pieceSize, string piecePos) : 
        name(pieceName), color(pieceColor), material(pieceMaterial), size(pieceSize), pos(piecePos) {}

    string getName() const { return name; }
    string getColor() const { return color; }
    string getMaterial() const { return material; }
    float getSize() const { return size; }
    string getPosition() const { return pos; }  
    
    void setPosition(string newPos) { pos = newPos; }
};

int main() 
{
    ChessPiece bishop("Bishop", "Black", "Wood", 2.5, "a1"); 

    cout << "Piece: " << bishop.getName() << endl
         << "Color: " << bishop.getColor() << endl
         << "Material: " << bishop.getMaterial() << endl
         << "Size: " << bishop.getSize() << endl
         << "Position: " << bishop.getPosition() << endl;

    bishop.setPosition("f4");
    cout << "New Position: " << bishop.getPosition() << endl;

    return 0;
}
