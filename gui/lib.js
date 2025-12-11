// @ts-check
import htm from "./lib/htm.js";
import { h, render } from "./lib/preact.js";
import { signal } from "./lib/signals.js";

export const html = htm.bind(h);

export { render, signal };
