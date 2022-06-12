#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetLineWidth(1.5);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofColor color;
	float len = 5;
	bool flag = true;

	for (int x = -220; x <= 220; x += 220) {

		for (int y = -220; y <= 220; y += 220) {

			ofPushMatrix();
			ofTranslate(x, y);
			if (flag) {
			
				ofRotateY(ofGetFrameNum());
			}
			else {

				ofRotateX(ofGetFrameNum());
			}

			int hue = ofRandom(255);
			for (float radius = 15; radius <= 100; radius += len * 2) {

				ofRotateZ(ofRandom(360));
				ofRotateY(ofRandom(360));
				ofRotateX(ofRandom(360));

				vector<glm::vec2> vertices_1, vertices_2;
				float deg_start = ofRandom(360) + ofGetFrameNum() * ofRandom(3, 10);

				for (float deg = deg_start; deg < deg_start + 270; deg += 1) {

					vertices_1.push_back(glm::vec2((radius - len * 0.5) * cos(deg * DEG_TO_RAD), (radius - len * 0.5) * sin(deg * DEG_TO_RAD)));
					vertices_2.push_back(glm::vec2((radius + len * 0.5) * cos(deg * DEG_TO_RAD), (radius + len * 0.5) * sin(deg * DEG_TO_RAD)));
				}

				reverse(vertices_2.begin(), vertices_2.end());

				color.setHsb(hue, 150, 255);

				ofNoFill();
				ofSetColor(color);

				ofBeginShape();
				ofVertices(vertices_1);
				ofVertices(vertices_2);
				ofEndShape(true);

				hue = (hue + (int)ofRandom(20, 120)) % 255;
			}

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}