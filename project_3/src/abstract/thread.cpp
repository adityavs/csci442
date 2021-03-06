#include "thread.h"
#include <assert.h>

using namespace std;

Thread::Thread() {
 StateString = {
    "NEW",
    "READY",
    "RUNNING",
    "BLOCKED",
    "EXIT"
  };
}

/**
 * Sets the thread to ready.
 */
void Thread::set_ready(size_t time) {
  previous_state = current_state;
  current_state = READY;
  if (previous_state == BLOCKED) {
    io_time += time;
  } else if (previous_state == RUNNING) {
    service_time += time;
  }
}

/**
 * Sets the thread to running. Also records the start time if this is the
 * first time the thread has run.
 */
void Thread::set_running(size_t time) {
  if (start_time == -1) {
    start_time = time;
  }
  previous_state = current_state;
  current_state = RUNNING;
  if (previous_state == BLOCKED) {
    io_time += time;
  }
}

/**
 * Sets the thread to blocked, waiting on IO.
 */
void Thread::set_blocked(size_t time) {
  previous_state = current_state;
  current_state = BLOCKED;
  if (previous_state == RUNNING) {
    service_time += time;
  }
}

/**
 * Sets the thread to finished.
 */
void Thread::set_finished(size_t time) {
  end_time = time;
  previous_state = current_state;
  current_state = EXIT;
}

/**
 * Add to the service time
 */
void Thread::set_cpu_finished(size_t time) {
  if (current_state == RUNNING) {
    service_time += time;
  }
}

/**
 * Returns the response time for this thread.
 */
size_t Thread::response_time() const {
  return start_time - arrival_time;
}

/**
 * Returns the turnaround time for this thread.
 */
size_t Thread::turnaround_time() const {
  return end_time - arrival_time;
}
