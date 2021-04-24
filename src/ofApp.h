#pragma once

#include "ofMain.h"
#include "Physics.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	Physic physics = Physic(1920,1080,500);
	ofEasyCam cam;
	//ofMaterial material;
	ofLight pointLight;
	ofLight pointLight2;
	ofLight pointLight3;
	ofLight pointLight4;
	ofLight pointLight5;
	ofLight pointLight6;
	ofLight pointLight7;
	ofLight pointLight8;



	//gui
	
	
	ofxPanel gui;
	ofxFloatSlider sun_radius;
	ofxFloatSlider sun_radius2;
	ofxFloatSlider sun_mass;
	ofxFloatSlider sun_mass2;
	ofxFloatSlider G_val;
	ofxIntSlider N_planets;
	ofxFloatSlider Planets_min_mass;
	ofxFloatSlider Planets_max_mass;
	ofxButton submitButton;
	ofxToggle moonsButton;
	ofxIntSlider moon_chance;


	ofxPanel gui_active;
	bool finished_setup = false;

	void setup_physics();


	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
