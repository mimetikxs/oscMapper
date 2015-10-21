//
//  OscController.h
//  example_oscMapper
//
//  Created by Nestor Rubio Garcia on 12/07/2015.
//
//

#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxPanel.h"


class OscController {
    
public:
    OscController();
    
    void setup(int port);
    
    void addPanel(ofxPanel* panel);
    
    void enableMappingMode();
    void disableMappingMode();
    void toggleMappingMode();
    
    void saveOscMapping();
    void loadOscMapping();
    
    void enable();
    void disable();
    bool isEnabled(){ return bEnabled; }
    
    // TODO:
    //void addOutput(string host, int port);
    void enableParameterSync();
    void disableParameterSync();
    
private:
    
    bool bMapModeEnabled;
    bool bEnabled;
    
    bool isGroup(ofAbstractParameter& param);
    void addGroup(ofxGuiGroup* group);
    
    vector<ofxPanel*> panels;
    map<string,ofxBaseGui*> controls;   // controls (view of the parameters)
    map<string,int> controlsNameCount;  // count of control names
    
    string selected;
    string address;
    
    map<string, string> addressToName;
    
    ofxOscReceiver oscIn;
    //ofxOscSender oscOut;
    vector<ofxOscSender*> oscOut;
    
    void draw(ofEventArgs& args);
    void update(ofEventArgs& args);
    void mouseReleased(ofMouseEventArgs& mouse);
    void keyPressed(ofKeyEventArgs& key);
    
    // drawing helpers
    ofTrueTypeFont verdana14;
    const ofColor colorNormal = ofColor(0, 200, 150, 150);
    const ofColor colorHighlight = ofColor(80, 220, 100, 170);
    void drawOverlay(ofxBaseGui *control, ofColor fillColor, ofColor lineColor);
    
    bool isMappeable(ofAbstractParameter& p);
    bool matchTypes(string controlName, ofxOscMessage message);
    string mismatchMessage;
    
    
    // parameter syncing
    
    // found groups, we use a map to avoid storing the same group twice
    map<string,ofParameterGroup*> syncGroups;
    
    void parameterChanged( ofAbstractParameter & parameter );
};

