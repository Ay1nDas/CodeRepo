import { renderCheckoutCart } from './checkout/orders.js';
import { renderPaymentSummary } from './checkout/payment.js';
import { loadProductsFetch } from '../data/products.js';

async function loadPage() {
  await loadProductsFetch();

  renderPage();
}
loadPage();

// loadProductsFetch().then(() => {
//   console.log('rendering Page');
//   renderPage();
// });

export function renderPage() {
  renderCheckoutCart();
  renderPaymentSummary();
}
