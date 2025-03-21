import { renderCheckoutCart } from './checkout/orders.js';
import { renderPaymentSummary } from './checkout/payment.js';
import { loadProducts } from '../data/products.js';

new Promise((resolve) => {
  loadProducts(resolve);
}).then(() => {
  console.log('rendering Page');
  renderPage();
});

export function renderPage() {
  renderCheckoutCart();
  renderPaymentSummary();
}
