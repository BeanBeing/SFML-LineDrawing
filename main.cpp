#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <vector>

// Starting coordinate for where it starts
struct Coordinate{
   int x, y;
} dot;

int main()
{
   // Display a window with a renderer
   sf::RenderWindow window(sf::VideoMode(640, 480), "Draw-lines");

   dot.x = 100; dot.y = 100;

   /**-- Handles Text and Font --**/
   sf::Font simpleFont;
   simpleFont.loadFromFile("NotoSans-Regular.ttf");
   sf::Text text;
   text.setFont(simpleFont);
   text.setString("Hello World");
   text.setFillColor(sf::Color::Red);
   text.setCharacterSize(12);

   // Framerate
   window.setFramerateLimit(60);
   while(window.isOpen())
   {
      sf::Event event;
      
      while(window.pollEvent(event))
      {
         if(event.type == sf::Event::Closed)
         {
            window.close();
         }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
         {
            window.close();
         }

         // For every mouse left click, display
         if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
         {
            int x = sf::Mouse::getPosition(window).x, y = sf::Mouse::getPosition(window).y;
            sf::Vertex line[] =
            {
               sf::Vertex(sf::Vector2f(dot.x, dot.y)),
               sf::Vertex(sf::Vector2f(x, y)),
            };

            text.setPosition(x, y);


            line[0].color = sf::Color::White;
            line[1].color = sf::Color::Blue;
            window.draw(line, 2, sf::Lines);
            window.draw(text);
         }
      }

      window.display();
   }
   
   return 0;
}
