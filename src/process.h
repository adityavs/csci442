#pragma once
#include "thread.h"
#include <vector>

/**
 * The type of the process (representing its relative priority).
 */
enum ProcessType {
  SYSTEM = 0,
  INTERACTIVE = 1,
  NORMAL = 2,
  BATCH = 3
};

/**
 * Represents a simple process, which encapsulates one or more threads.
 */
struct Process {

  /**
   * The ID of this process.
   */
  int pid;

  /**
   * The type of the process.
   */
  ProcessType type;

  /**
   * All threads belonging to this process (as pointers).
   */
  std::vector<Thread*> threads;
};
