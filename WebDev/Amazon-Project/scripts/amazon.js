import { cart, totalCartItem, addToCart } from '../data/cart.js';
import { products, loadProducts } from '../data/products.js';
import { formatCurrency } from './utils/money.js';

loadProducts(renderCart);

function renderCart() {
  let productsHTML = '';

  products.forEach((product) => {
    productsHTML += `
      <div class="product-container">
        <div    class="product-image-container">
          <img class="product-image"
            src="${product.image}">
        </div>

        <div class="product-name limit-text-to-2-lines">
          ${product.name}
        </div>

        <div class="product-rating-container">
          <img class="product-rating-stars"
            src="${product.getStars()}">
          <div class="product-rating-count link-primary">
            ${product.rating.count}
          </div>
        </div>

        <div class="product-price">
          $${product.getPrice()}
        </div>

        <div class="product-quantity-container">
          <select>
            <option selected value="1">1</option>
            <option value="2">2</option>
            <option value="3">3</option>
            <option value="4">4</option>
            <option value="5">5</option>
            <option value="6">6</option>
            <option value="7">7</option>
            <option value="8">8</option>
            <option value="9">9</option>
            <option value="10">10</option>
          </select>
        </div>
        <div class = "extra-details">${product.extraDetails()}</div>
        <div class="product-spacer"></div>

        <div class="added-to-cart">
          <img src="images/icons/checkmark.png">
          Added
        </div>

        <button class="add-to-cart-button js-add-to-cart button-primary" data-product-id="${
          product.id
        }">
          Add to Cart
        </button>
      </div>
    `;
  });

  function updateCartQuantity() {
    // if (totalCartItem) {
    //   document.querySelector('.cart-quantity').innerText = totalCartItem;
    // } else {
    //   document.querySelector('.cart-quantity').innerText = ``;
    // }

    document.querySelector('.cart-quantity').innerText = totalCartItem;
  }
  updateCartQuantity();

  document.querySelector('.products-grid').innerHTML = productsHTML;

  // console.log(productsHTML);

  document.querySelectorAll('.js-add-to-cart').forEach((button) => {
    button.addEventListener('click', () => {
      // const productID = button.dataset.productId;
      addToCart(button.dataset.productId);
      // console.log('click');

      updateCartQuantity();
      console.log(cart);
      console.log(totalCartItem);
    });
  });

  // localStorage.removeItem('cart');
  // localStorage.removeItem('totalCartItem');
}
