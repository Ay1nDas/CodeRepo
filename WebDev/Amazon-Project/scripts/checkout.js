import { renderCart } from './checkout/orders.js';
import { renderPaymentSummary } from './checkout/payment.js';

export function renderPage() {
  renderCart();
  renderPaymentSummary();
}
renderPage();
