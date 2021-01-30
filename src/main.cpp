#include <iostream>
#include "AudioPlayer.hpp"

using namespace std;

int main(int argc, char** argv) {
	if (argc < 2) {
		cout<<"Missing argument, you need to give a music file as an argument"<<endl;
		return -1;
	}
	AudioPlayer audioPlayer;
	audioPlayer.playSound(argv[1]);
	return 0;
}