
#define CUSTOM_SETTINGS
#define INCLUDE_VOICE_RECOGNIZER_SHIELD
#define INCLUDE_MUSIC_PLAYER_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#include <OneSheeld.h>
int Rledpin=13;
int Yledpin=12;
int Gledpin=11;

/* Voice commands set by the user. */
const char allOnCommand[] = "all on";
const char allOffCommand[] = "all off";
const char whatCommand[] = "yellow";
const char nextCommand[] = "green";
const char BlueCommand[] = "blue";

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  /* Start Communication. */
  OneSheeld.begin();
  /* Error Commands handiling. */
  VoiceRecognition.setOnError(error);
  
  VoiceRecognition.start();
}

void loop () 
{
  /* Check if new command received. */
  if(VoiceRecognition.isNewCommandReceived())
  {
    /* Compare the play command. */
    if(!strcmp(allOnCommand,VoiceRecognition.getLastCommand()))
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
    }
    /* Compare the pause command. */
    else if (!strcmp(allOffCommand,VoiceRecognition.getLastCommand()))
    {
       digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
    }
    /* Compare the stop command. */
    else if (!strcmp(whatCommand,VoiceRecognition.getLastCommand()))
    {
       digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
       digitalWrite(11,LOW);
    }
    /* Compare the next command. */
    else if (!strcmp(nextCommand,VoiceRecognition.getLastCommand()))
    {
      digitalWrite(13,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(12,LOW);
       
    }
    else if (!strcmp(BlueCommand,VoiceRecognition.getLastCommand()))
    {
      
      digitalWrite(12,LOW);
      digitalWrite(13,HIGH);
       digitalWrite(11,LOW);
    }
  }
}

/* Error checking function. */
void error(byte errorData)
{
  /* Switch on error and print it on the terminal. */
  switch(errorData)
  {
    case NETWORK_TIMEOUT_ERROR: Terminal.println("Network timeout");break;
    case NETWORK_ERROR: Terminal.println("Network Error");break;
    case AUDIO_ERROR: Terminal.println("Audio error");break;
    case SERVER_ERROR: Terminal.println("No Server");break;
    case SPEECH_TIMEOUT_ERROR: Terminal.println("Speech timeout");break;
    case NO_MATCH_ERROR: Terminal.println("No match");break;
    case RECOGNIZER_BUSY_ERROR: Terminal.println("Busy");break;
  }
}
