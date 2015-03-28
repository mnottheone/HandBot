//
#include <VirtualWire.h>
#define LEDPIN 13

char *controller;

void setup()
{
  pinMode(LEDPIN,OUTPUT);
  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(12);
  vw_setup(4000);// speed of data transfer Kbps
}
// Need to read sensors data to achieve final target i.e to control by hand //

// should be snchronised with reciever by same delays
void loop()
{
  controller="1"  ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(LEDPIN,1);
  delay(6000);
  controller="0"  ;
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(LEDPIN ,0);
  delay(3000);

}
