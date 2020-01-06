#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Audio.hpp>
#include <iostream>


using namespace std; 

sf::SoundBuffer loadSoundBuffer(const string& waveFilename)
{
  sf::SoundBuffer mySoundBuffer;
  if (!mySoundBuffer.loadFromFile(waveFilename))
  {
    cout << "Can not load sound from " << waveFilename << endl;  
    exit(1);
  }
  return mySoundBuffer;
}
  
sf::Sound createSound(const sf::SoundBuffer& mySoundBuffer)
{
  sf::Sound mySound(mySoundBuffer);
  return mySound;
}

int main(){
	sf::RenderWindow window(sf::VideoMode(1024, 786), "Test 32");
	window.setFramerateLimit(60);
	sf::Texture texture;
	texture.loadFromFile("Asset/texture/tiles1.png");
	sf::Sprite background{texture};
	background.setPosition(0,0);
	sf::SoundBuffer mySoundBuffer = loadSoundBuffer("Asset/Sound/main-bgm.wav");
	sf::Sound mySound = createSound(mySoundBuffer);
	
	bool started = true;

	while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
			if(!started){
				if (e.type == sf::Event::Closed){window.close();}
			}
			else{
				window.draw(background);
				mySound.play();
				started = false;
				if (e.type == sf::Event::Closed){window.close();}
			}
			
        }
    }

	window.display();
	
	return 0;
}
