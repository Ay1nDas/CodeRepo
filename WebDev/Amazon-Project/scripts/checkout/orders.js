import { renderPage } from '../checkout.js';
import { products, getProduct } from '../../data/products.js';
import {
  cart,
  totalCartItem,
  deleteItem,
  changeDelivery,
} from '../../data/cart.js';
import { formatCurrency } from '../utils/money.js';
import {
  deliveryOptions,
  generateDelivery,
  getDeliveryOption,
} from '../../data/delivery.js';

import dayjs from 'https://unpkg.com/dayjs@1.11.10/esm/index.js';

console.log(cart);

export function renderCart() {
  if (totalCartItem < 2) {
    document.querySelector(
      '.js-item-count'
    ).innerHTML = ` ${totalCartItem} item `;
  } else {
    document.querySelector(
      '.js-item-count'
    ).innerHTML = ` ${totalCartItem} items `;
  }

  // console.log(cart);
  let orderHTML = '';

  cart.forEach((cartItem, index) => {
    const productID = cartItem.productID;
    const display_product = getProduct(productID);
    // console.log(display_product);

    const today = dayjs();

    const delOpt = getDeliveryOption(cartItem.deliveryId);
    const deliveryDate = today.add(delOpt.days, 'days').format('dddd, MMMM D');

    orderHTML += `
      <div class="cart-item-container 
        js-item-${productID}">
        <div class="delivery-date">Delivery date: ${deliveryDate}</div>

        <div class="cart-item-details-grid">
          <img
            class="product-image"
            src="${display_product.image}"
          />

          <div class="cart-item-details">
            <div class="product-name">
            ${display_product.name}
            </div>
            <div class="product-price">
            $${formatCurrency(display_product.priceCents)}
            </div>
            <div class="product-quantity">
              <span> Quantity: <span class="quantity-label">${
                cartItem.quantity
              }</span> </span>
              <span class="update-quantity-link link-primary">
                Update
              </span>
              <span class="js-delete-quantity-link delete-quantity-link link-primary" data-product-index="${index}">
                Delete
              </span>
            </div>
          </div>

          <div class="delivery-options">
            <div class="delivery-options-title">
              Choose a delivery option:
            </div>
            ${generateDelivery(productID, cartItem.deliveryId, index)}
          </div>
        </div>
      </div>
    `;
  });
  document.querySelector('.js-order-summary').innerHTML = orderHTML;

  document.querySelectorAll('.js-delete-quantity-link').forEach((del_btn) => {
    del_btn.addEventListener('click', () => {
      const removedItem = deleteItem(del_btn.dataset.productIndex);
      // renderCart();
      renderPage();
    });
  });

  document
    .querySelectorAll('.js-delivery-option')
    .forEach((deliveryElement) => {
      const deliveryId = deliveryElement.dataset.deliveryId;
      const productId = deliveryElement.dataset.productId;
      deliveryElement.addEventListener('click', () => {
        changeDelivery(productId, deliveryId);
        // renderCart();
        renderPage();
      });
    });
}
