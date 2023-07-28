#include <SFML/Graphics.hpp>
#include <vector>

// ... Rest of your chess-related code ...

// Function to draw the chessboard and pieces
void drawChessboard(sf::RenderWindow& window, const std::vector<std::vector<ChessPiece>>& chessboard) {
    // Calculate the size of each square based on the window dimensions and board size
    float squareSizeX = static_cast<float>(window.getSize().x) / BOARD_SIZE;
    float squareSizeY = static_cast<float>(window.getSize().y) / BOARD_SIZE;

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            sf::RectangleShape square(sf::Vector2f(squareSizeX, squareSizeY));
            square.setPosition(static_cast<float>(col) * squareSizeX, static_cast<float>(row) * squareSizeY);

            if ((row + col) % 2 == 0) {
                square.setFillColor(sf::Color::White);
            }
            else {
                square.setFillColor(sf::Color::Black);
            }

            // ... Code to draw the pieces on each square ...
            // You can use SFML shapes to represent the pieces, e.g., sf::CircleShape for pawns, sf::RectangleShape for others.
            // Set appropriate colors and positions for each piece.

            window.draw(square);
        }
    }
}

int main() {
    // ... Previous chess-related code, e.g., initializeChessboard() ...

    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chess Game");

    // Set the frame rate (optional)
    window.setFramerateLimit(60);

    // Game loop
    while (window.isOpen()) {
        // Process events
        // ... Previous event handling code ...

        // Clear the window
        window.clear();

        // Draw the chessboard and pieces
        drawChessboard(window, chessboard);

        // Display the updated window
        window.display();
    }

    return 0;
}
