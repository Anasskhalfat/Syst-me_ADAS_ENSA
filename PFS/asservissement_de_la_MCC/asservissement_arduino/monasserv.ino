#include <FlexiTimer2.h>
#include <digitalWriteFast.h> 
 
// Codeur incrémental
#define codeurInterruptionA 0
#define codeurInterruptionB 1
#define codeurPinA 2
#define codeurPinB 3
#define pot A0
volatile long ticksCodeur = 0;
 
// Moteur CC
#define directionMoteur  4
#define pwmMoteur  6
 
// Cadence d'envoi des données en ms
#define TSDATA 100
unsigned long tempsDernierEnvoi = 0;
unsigned long tempsCourant = 0;
 
// Cadence d'échantillonnage en ms
#define CADENCE_MS 10
volatile double dt = CADENCE_MS/1000.;
volatile double temps = -CADENCE_MS/1000.;
 
volatile double omega;
volatile double vitesse;

volatile double commande = 0.;
volatile double vref;
volatile double vi;
double v; 
// PID
volatile double Kp = 0.3;
volatile double Ki = 3;
volatile double P_x = 0.;
volatile double I_x = 0.;
volatile double ecart = 0.;
 
// Initialisations
void setup(void) {
 
  // Codeur incrémental
  pinMode(codeurPinA, INPUT);      // entrée digitale pin A codeur
  pinMode(codeurPinB, INPUT);      // entrée digitale pin B codeur 
  pinMode(pot, INPUT); 
  digitalWrite(codeurPinA, HIGH);  // activation de la résistance de pullup
  digitalWrite(codeurPinB, HIGH);  // activation de la résistance de pullup
  attachInterrupt(codeurInterruptionA, GestionInterruptionCodeurPinA, CHANGE);
  attachInterrupt(codeurInterruptionB, GestionInterruptionCodeurPinB, CHANGE);
  vi=45;
  
  // Moteur CC
  pinMode(directionMoteur, OUTPUT);
  pinMode(pwmMoteur, OUTPUT);
 
  // Liaison série
  Serial.begin(9600);
  Serial.flush();
 
  // Compteur d'impulsions de l'encodeur
  ticksCodeur = 0;
 
  // La routine isrt est exécutée à cadence fixe
  FlexiTimer2::set(CADENCE_MS, 1/1000., isrt); // résolution timer = 1 ms
  FlexiTimer2::start();
 
}
 int msg=1000;
// Boucle principale
void loop() {
   vref=map(analogRead(pot),0,1023,0,vi);
  // Ecriture des données sur la liaison série
  ecritureData();
  
  
 
}
 
void isrt(){
 
  int codeurDeltaPos;
  double tensionBatterie;
 
  // Nombre de ticks codeur depuis la dernière fois
  codeurDeltaPos = ticksCodeur;
  ticksCodeur = 0;
 
  // Calcul de la vitesse de rotation
  omega = ((2.*3.141592*((double)codeurDeltaPos))/1920.)/dt; // en rad/s
  vitesse=(omega*60)/(2*3.141592);    // en tr/min
  
  
  /******* Régulation PID ********/
  // Ecart entre la consigne et la mesure
  vref=map(analogRead(pot),0,1023,0,vi);
  ecart = vref - omega;
 
  // Terme proportionnel
  P_x = Kp * ecart;
 
  // Calcul de la commande
  commande = P_x + I_x;
 
  // Terme intégral (sera utilisé lors du pas d'échantillonnage suivant)
  I_x = I_x + Ki * dt * ecart;
  /******* Fin régulation PID ********/
 
  // Envoi de la commande au moteur
  tensionBatterie = 15.0;
  CommandeMoteur(commande, tensionBatterie);
 
  temps += dt;

  if(Serial.available()>0){
   msg=Serial.read();
   vi= (msg*2*3.141592/60)+6;
   vref=map(analogRead(pot),0,1023,0,vi);
  
   }else{
       vref=map(analogRead(pot),0,1023,0,vi);

   }
}
 
void ecritureData(void) {
 
  // Ecriture des données en sortie tous les TSDATA millisecondes
  tempsCourant = millis();
  if (tempsCourant-tempsDernierEnvoi > TSDATA) {
    Serial.print("temps");
    Serial.print(temps);
 
    Serial.print("  ,vitesse:");
    Serial.print(omega);
    Serial.print("rad/s");
    Serial.print("    ");
    Serial.print((omega*60)/(2*3.141592));
    Serial.print("tr/min");
    Serial.print("    ");
    Serial.print("vref=");
    Serial.print(vref);
 
    Serial.print("\r");
    Serial.print("\n");
 
    tempsDernierEnvoi = tempsCourant;
  }
}
 
void CommandeMoteur(double tension, double tensionBatterie)
{
    int tension_int;
 
    // Normalisation de la tension d'alimentation par
        // rapport à la tension batterie
    tension_int = (int)(255*(tension/tensionBatterie));
 
    // Saturation par sécurité
    if (tension_int>255) {
        tension_int = 255;
    }
    if (tension_int<-255) {
        tension_int = -255;
    }
 
        // Commande PWM
    if (tension_int>=0) {
        digitalWrite(directionMoteur, LOW);
        analogWrite(pwmMoteur, tension_int);
    }
    if (tension_int<0) {
        digitalWrite(directionMoteur, HIGH);
        analogWrite(pwmMoteur, -tension_int);
    }
}
 
// Routine de service d'interruption attachée à la voie A du codeur incrémental
void GestionInterruptionCodeurPinA()
{
  if (digitalReadFast(codeurPinA) == digitalReadFast(codeurPinB)) {
    ticksCodeur--;
  }
  else {
    ticksCodeur++;
  }
}
 
// Routine de service d'interruption attachée à la voie B du codeur incrémental
void GestionInterruptionCodeurPinB()
{
  if (digitalReadFast(codeurPinA) == digitalReadFast(codeurPinB)) {
    ticksCodeur++;
  }
  else {
    ticksCodeur--;
  }
}
