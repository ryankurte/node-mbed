

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "NanostackInterface.h"
#include "mbed-trace/mbed_trace.h"
#include "mbed.h"
#include "rtos.h"

#include "NanostackRfPhyEfr32.h"
#include "sl_trng.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

LoWPANNDInterface mesh;
NanostackRfPhyEfr32 rf_phy;

Ticker ticker;

static Mutex SerialOutMutex;
void serial_out_mutex_wait() { SerialOutMutex.lock(); }
void serial_out_mutex_release() { SerialOutMutex.unlock(); }

static void blink() { led1 = !led1; }
void start_blinking() { ticker.attach(blink, 1.0); }

int main(int argc, char **argv) {

	ticker.attach(blink, 1.0);

	while (1) {
		led2 = !led2;
		wait(0.5);
	}

#if 0
  ticker.attach(blink, 0.5);

  // Setup packet trace outputs
  mbed_trace_init();
  mbed_trace_print_function_set(trace_printer);
  mbed_trace_mutex_wait_function_set(serial_out_mutex_wait);
  mbed_trace_mutex_release_function_set(serial_out_mutex_release);

  // Initialise mesh
  mesh.initialize(&rf_phy);
  int error = mesh.connect();
  if (error) {
    printf("Connection failed! %d\n", error);
    return error;
  }

  // Await IP allocation
  while (NULL == mesh.get_ip_address())
    Thread::wait(500);

  ticker.detach();
  ticker.attach(blink, 3.0);

  // Mesh connected
  printf("connected. IP = %s\n", mesh.get_ip_address());

  while (1) {
  }
#endif
}
