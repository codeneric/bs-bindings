let controller = AbortController.make();

AbortController.abort(controller);
let signal = AbortController.getSignal(controller);