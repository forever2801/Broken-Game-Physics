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
	texture.loadFromFile("Asset/texture/gameplayBackground.jpg");
	sf::Sprite background{texture};
	background.setPosition(0,0);
	sf::SoundBuffer mySoundBuffer = loadSoundBuffer("Asset/Sound/main-bgm.wav");
	sf::Sound mySound = createSound(mySoundBuffer);

	while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }
    }
	bool started = true;
	window.clear();
	if(!started){
	}
	else{
		window.draw(background);
		mySound.play();
	}

	window.display();
	
	return 0;
}