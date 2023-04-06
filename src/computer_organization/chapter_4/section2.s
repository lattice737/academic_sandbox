// 4.2 Concepts

/*
Vocabulary
==========
* Combinational logic elements - elements with output dependent only on current inputs; given like inputs, they will always
  produce the same output
* State logic elements - elements that have internal storage for preserving values that represent their state and therefore
  the computer; they always have at least two inputs, a value to be written and the clock determining when to write, and an
  output, a value written in an earlier clock cycle
* Clocking methodology - an approach used to determine when data are valid and stable, relative to the clock
* Clock edge - a quick transition from low to high voltage
* Edge-triggered clocking - a clocking scheme in which all state changes occur on a clock edge
* Control signal - a signal used for multiplexor selection or for directing the operation of a functional unit
* Data signal - a signal containing information on which a functional unit operates
* Asserted - characterizes a signal that is logically high
* Deasserted - characterizes a signal that is logically low
* Bus - a signal that is wider than 1 bit
* Color - indicates a control signal contrary to a signal carrying data

General
=======
~ State elements can be read at any time
~ Logic components that contain state information are also called sequential, because their outputs depend on both their inputs
  and their contents (internal state)
~ Any collection of combinational logic must have inputs from a set of state elements and its outputs written into a set of state
  elements, because only state elements can store data
~ Edge-triggered methodology allows for reading registers and sending a value through combinational logic, and writing that
  register, all in the same clock cycle, because inputs to the combinational logic block cannot change except on the chosen edge
~ For 64-bit LEGv8 architecture, nearly all state and logic elements have inputs and outputs that are 64 bits wide, since that's
  the width of most data handled by the processor
*/

    