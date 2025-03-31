// C++ code
//
#define toggle(x) digitalWrite(x, !digitalRead(x));

//const
const int green = 12;
const int yellow = 11;
const int red1 = 10;
const int red2 = 9;
const int button = 2;
const int speaker = 5;

volatile int state = 0;

//debounce code
unsigned long int last_debounce_time = 0;
unsigned long int debounce_delay = 50;//increase if flickers

/*
unsigned long int current_debounce_time = millis();
if ((current_debounce_time - last_debounce_time) > debounce_delay){
	//stuff in here
}
last_debounce_time = current_debounce_time;
*/


const int maxtime = 30;//max time in sec
int max_ms = maxtime*1000; // max time in ms
int max_iter = maxtime*100;
unsigned long int start_of_timer = millis();//start of program


void setup()
{
   pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(speaker, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), next, RISING);

}

//change value represents time between toggles.
int place_holder = 1;

void loop()
{
  switch(state){
    case 0:
    digitalWrite(green, 1);
    digitalWrite(yellow, 0);
    digitalWrite(red2, 0);
    digitalWrite(red1, 0);
    digitalWrite(speaker, 1);
    state = 1;
    //green
      //0.33*max_iter
      for (int t = 0; t < 10; t++){
        //delay between toggles
        for(int i = 0; i < max_iter*0.033; i++){//10 ms per iteration
          delay(10);
          if(state == 0)
            break;
        }
        if(state == 0)
            break;
        //toggle
        toggle(green);
        toggle(speaker);
      //
      }//end of green
      if(state == 0)
            break;
      //turn green off
      digitalWrite(green, 0);
      digitalWrite(speaker, 0);


    //yellow
      //0.27*max_iter
      for (int t = 0; t < 10; t++){
        //toggle
        toggle(yellow);
        toggle(speaker);
        //delay between toggles
        for(int i = 0; i < max_iter*0.027; i++){//10 ms per iteration
          delay(10);
          if(state == 0)
            break;
        }
        if(state == 0)
            break;
        

      //
      }//end of yellow
      if(state == 0)
            break;
      //turn yellow off
      digitalWrite(yellow, 0);
      digitalWrite(speaker, 0);

    //red1
      //0.20*max_iter
      for (int t = 0; t < 10; t++){
        //toggle
        toggle(red1);
        toggle(speaker);
        //delay between toggles
        for(int i = 0; i < max_iter*0.02; i++){//10 ms per iteration
          delay(10);
          if(state == 0)
            break;
        }
        if(state == 0)
            break;
        

      //
      }//end of red1
      if(state == 0)
            break;
      //turn red1 off
      digitalWrite(red1, 0);
      digitalWrite(speaker, 0);

    //red2
      //0.13*max_iter
      for (int t = 0; t < 10; t++){
        //toggle
        toggle(red2);
        toggle(speaker);
        //delay between toggles
        for(int i = 0; i < max_iter*0.013; i++){//10 ms per iteration
          delay(10);
          if(state == 0)
            break;
        }
        if(state == 0)
            break;
        

      //
      }//end of red2
      if(state == 0)
            break;
      //turn red2 off
      //digitalWrite(red2, 0);

    //red flash
      //0.07*max_iter
      for (int t = 0; t < 10; t++){//number of toggles
        //toggle
        toggle(red2);
        toggle(red1);
        toggle(speaker);
        //delay between toggles
        for(int i = 0; i < max_iter*0.007; i++){//10 ms per iteration
          delay(10);
          if(state == 0)
            break;
        }
        if(state == 0)
            break;
      //
      }//end of red flash
      if(state == 0)
            break;
      //turn red off
      digitalWrite(red2, 0);
      digitalWrite(red1, 0);
      digitalWrite(speaker, 0);

    int end_cycle1 [8] = { 12, 12, 11, 11, 10, 10, 9, 9};
    int end_cycle2 [8] = { 12, 11, 10, 9, 12, 11, 10, 9};

    //celebration
    for (int h = 0; h < 3; h++){
      for (int k = 0; k < 8; k++){//go through end cycle 1
        for(int i = 0; i < max_iter*0.01; i++){//10 ms per iteration
          delay(10);
          if(state == 0)
            break;
        }
        if(state == 0)
            break;
        //toggle
        toggle(end_cycle1[k]);
      }//end of celebration cycle 1
      if(state == 0)
        break;    
    }
    if(state == 0)
      break;

    //celebration
    for (int h = 0; h < 3; h++){
      for (int k = 0; k < 8; k++){//go through end cycle 1
        for(int i = 0; i < max_iter*0.01; i++){//10 ms per iteration
          delay(10);
          if(state == 0)
            break;
        }
        if(state == 0)
            break;
        //toggle
        toggle(end_cycle2[k]);
      }//end of celebration cycle 1
      if(state == 0)
        break;    
    }
    if(state == 0)
      break;


    default:
      //


      digitalWrite(green, 1);
      digitalWrite(yellow, 1);
      digitalWrite(red2, 1);
      digitalWrite(red1, 1);
      break;
  }
}

void next(){
  unsigned long int current_debounce_time = millis();
  if ((current_debounce_time - last_debounce_time) > debounce_delay){
      //stuff in here
    state = 0;
  }
  last_debounce_time = current_debounce_time;
};