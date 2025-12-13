// @ts-check
import "./htm/App.js";
import { pushContent } from "./htm/Input.js";

/**
 * @param {string} content
 */
export function load(content) {
  /** @type import("./data.js").Data */
  const data = JSON.parse(content);
  pushContent(data);
}
