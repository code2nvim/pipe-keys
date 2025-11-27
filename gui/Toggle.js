// @ts-check
import { Input, input } from "./Input.js";
import { html, update } from "./lib.js";

export const toggle = {
  visible: true,
};

export function Toggle() {
  const handleClick = () => {
    input.visible = !input.visible;
    update(Toggle);
    update(Input);
  };

  return html`
    ${toggle.visible &&
      html`
        <button
          onClick="${handleClick}"
          class="absolute size-1/8 border text-white"
        >
          ${input.visible ? "visible" : "hidden"}
        </button>
      `}
  `;
}
