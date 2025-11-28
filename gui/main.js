// @ts-check
import "./App.js";
import { Input, input } from "./Input.js";
import { update } from "./lib.js";

/**
 * @param {string} content
 */
export function load(content) {
  input.content = content;
  update(Input);
}
