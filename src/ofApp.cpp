#include "ofApp.h"


void ofApp::setup_physics()
{
	physics.Set_G(G_val);
	physics.get_sun()->Set_Mass(sun_mass);
	physics.get_sun()->Set_Radius(sun_radius);
	physics.Set_moon_chance(moon_chance);
	double arr[2] = { Planets_min_mass,Planets_max_mass };
	physics.Set_Mass(arr);
	physics.create_planets(N_planets);
	gui.clear();
	gui.add(sun_radius.setup("Sun radius", physics.get_sun()->Get_r(), 1, 10000));
	gui.add(sun_mass.setup("Sun mass", physics.get_sun()->Get_Mass(), 1, 1000000));

}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(20);
	// shininess is a value between 0 - 128, 128 being the most shiny //
	/**this->material.setShininess(120);
	// the light highlight of the material //
	this->material.setSpecularColor(ofColor(255, 255, 255, 255));**/

	ofSetSphereResolution(70);
	cam.setNearClip(0.0f);
	cam.setFarClip(-1.0f);
	cam.setGlobalPosition({ 0,0,15000 });

	gui.setup();
	
	gui.add(sun_radius.setup("Sun radius", physics.get_sun()->Get_r(), 1, 10000));
	gui.add(sun_mass.setup("Sun mass", physics.get_sun()->Get_Mass(), 1, 1000000));
	gui.add(G_val.setup("Speed of animation", physics.Get_G(), 1, 200000));
	gui.add(Planets_min_mass.setup("Planet mass min", 10, 1, 100000));
	gui.add(Planets_max_mass.setup("Planet mass max", 1000, 1, 100000));
	gui.add(N_planets.setup("Number of Planets", 10, 1, 1000));
	gui.add(moonsButton.setup("use Moons", true));
	gui.add(moon_chance.setup("Chance of a moon", 10, 0, 100));
	gui.add(submitButton.setup("Submit"));
	

}

//--------------------------------------------------------------
void ofApp::update(){
	if (submitButton)
	{
		if (finished_setup)
		{
			pointLight.setPosition(0, physics.get_sun()->Get_r()+1, 0);
			pointLight2.setPosition(0, -physics.get_sun()->Get_r()-1, 0);

			pointLight3.setPosition(physics.get_sun()->Get_r()+1, 0, 0);
			pointLight4.setPosition(-physics.get_sun()->Get_r()-1, 0, 0);
			pointLight5.setPosition(-physics.get_sun()->Get_r()-1, 0, -physics.get_sun()->Get_r()-1);
			pointLight6.setPosition(physics.get_sun()->Get_r()+1, 0, physics.get_sun()->Get_r() + 1);
			pointLight7.setPosition(0, -physics.get_sun()->Get_r() - 1, physics.get_sun()->Get_r() + 1);
			pointLight8.setPosition(0, physics.get_sun()->Get_r() + 1, physics.get_sun()->Get_r() -1);

			physics.get_sun()->Set_Mass(sun_mass);
			physics.get_sun()->Set_Radius(sun_radius);
			physics.update_positions();
		}
		else
		{
			setup_physics();
			finished_setup = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if (submitButton && finished_setup)
	{
		ofEnableDepthTest();
		pointLight.enable();
		pointLight2.enable();
		pointLight3.enable();
		pointLight4.enable();
		pointLight5.enable();
		pointLight6.enable();
		pointLight7.enable();
		pointLight8.enable();
		cam.begin();
		ofFill();
		this->physics.draw_planets();
		cam.end();
		pointLight.disable();
		pointLight2.disable();
		pointLight3.disable();
		pointLight4.disable();
		pointLight5.disable();
		pointLight6.disable();
		pointLight7.disable();
		pointLight8.disable();
		ofDisableDepthTest();
		

	}
		gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
