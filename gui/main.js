import "./App.js";
import { Input, input } from "./Input.js";
import { update } from "./lib.js";

// webkit_web_view_evaluate_javascript
export function load(content) {
  input.content = content;
  update(Input);
}
