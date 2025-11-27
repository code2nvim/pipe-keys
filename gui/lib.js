import htm from "./lib/htm.js";
import { h, render } from "./lib/preact.js";

export const html = htm.bind(h);

export function identify(component) {
  // FooBar -> foo-bar
  const id = component.name
    .replace(/([a-z0-9])([A-Z])/g, "$1-$2")
    .replace(/([A-Z])([A-Z][a-z])/g, "$1-$2")
    .toLowerCase();

  return html`
    <div id="${id}" class="contents"><${component} /></div>
  `;
}

export function update(component) {
  // FooBar -> foo-bar
  const id = component.name
    .replace(/([a-z0-9])([A-Z])/g, "$1-$2")
    .replace(/([A-Z])([A-Z][a-z])/g, "$1-$2")
    .toLowerCase();

  render(
    html`
      <${component} />
    `,
    document.getElementById(id),
  );
}
