type controller;
type signal;

/* make a new controller */
[@bs.new] external make: unit => controller = "AbortController";

[@bs.get] external getSignal: controller => signal = "signal";
[@bs.send] external abort: controller => unit = "";