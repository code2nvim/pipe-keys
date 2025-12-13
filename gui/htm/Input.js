// @ts-check
import { html, signal } from "../lib.js";

/** @type import("../lib.js").Signal<import("../data.js").Data[]> */
const inputList = signal([]);

/**
 * @param {import("../data.js").Data} content
 */
export function pushContent(content) {
  inputList.value = [...inputList.value, content].slice(-10);
}

/** @type import("../lib.js").Signal<boolean> */
export const showInput = signal(true);

export function Input() {
  return html`
    <section class="flex grow items-center justify-center border-2 text-white">
      ${showInput.value &&
        inputList.value.map((input) =>
          html`
            <div>${input.name}</div>
          `
        )}
    </section>
  `;
}
