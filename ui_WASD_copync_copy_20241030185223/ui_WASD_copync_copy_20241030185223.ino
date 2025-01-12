 
 #define AP_SSID "VVERX23"
#define AP_PASS "VVERX2023"
#define rele_left 12
#define rele_right 13
#include <GyverPortal.h>
GyverPortal ui;

bool guard;

void build(){
GP.BUILD_BEGIN();
GP.THEME(GP_DARK);
GP.LABEL("Вкл.");
GP.BREAK();
GP.BUTTON_MINI("btn_forward", "W");
GP.BREAK();
GP.BUTTON_MINI("btn_left", "A");
GP.BREAK();
GP.BUTTON_MINI("btn_right", "D");
GP.BREAK();
GP.BUILD_END();
}

void action(){
if (ui.hold()){
if (ui.clickDown("btn_forward")) {
  digitalWrite(rele_left, 0);
  digitalWrite(rele_right, 0);
  Serial.println("Forward press!");
}
if (ui.clickDown("btn_left")) {
  digitalWrite(rele_left, 1);
  digitalWrite(rele_right, 0);
  Serial.println("Forward press!");
}
if (ui.clickDown("btn_right")) {
  digitalWrite(rele_left, 0);
  digitalWrite(rele_right, 1);
  Serial.println("Forward press!");
}
if (ui.clickUp("btn_Forward")) {
  digitalWrite(rele_left, 1);
  digitalWrite(rele_right, 1);
  Serial.println("Forward press!");
}
if (ui.clickDown("btn_left")) {
  digitalWrite(rele_left, 1);
  digitalWrite(rele_right, 1);
  Serial.println("Forward press!");
}
if (ui.clickDown("btn_right")) {
  digitalWrite(rele_left, 1);
  digitalWrite(rele_right, 1);
  Serial.println("Forward press!");
}
}
}

 

void setup(){
  pinMode (rele_left, OUTPUT);
  pinMode (rele_right, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASS);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());
 ui.attachBuild(build);
 ui.attach(action);
 ui.start();
}
void loop(){
  ui.tick();
 }
