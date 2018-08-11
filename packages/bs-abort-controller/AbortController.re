type controller;
type signal;

[@bs.new] external make : unit => controller = "AbortController";

[@bs.get] external getSignal : controller => signal = "signal";
[@bs.send] external abort : controller => unit = "";