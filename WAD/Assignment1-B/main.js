const fetchData = () => {
  const xhr = new XMLHttpRequest();
  xhr.open("GET", "https://jsonplaceholder.typicode.com/users");
  xhr.send();
  xhr.onload = () => {
    if (xhr.status === 200) {
      const res = JSON.parse(xhr.responseText);
      console.log(res);
      localStorage.setItem("users", JSON.stringify(res));
      displayData();
    } else {
      console.error("Error fetching data:", xhr.statusText);
    }
  };
};

const displayData = () => {
  const tbody = document.getElementById("tbody");
  const storedUser = JSON.parse(localStorage.getItem("users")) || [];
  
  // Build the entire string first (Faster performance)
  const rows = storedUser.map((user, index) => `
    <tr>
      <td>${index + 1}</td>
      <td>${user.name}</td>
      <td>${user.username}</td>
      <td>${user.email}</td>
      <td>${user.phone}</td>
      <td>${user.address?.city || ''}</td>
    </tr>
  `).join('');
  
  tbody.innerHTML = rows;
};

// Initial Data Load
fetchData();

const btn = document.getElementById("btn");
if (btn) {
  btn.addEventListener("click", (e) => {
    e.preventDefault(); // Prevent page refresh on submit
    
    const getValue = id => document.getElementById(id)?.value || '';

    const postObject = {
      name: getValue("name"),
      username: getValue("username"),
      email: getValue("email"),
      phone: getValue("phone"),
      address: {
        city: getValue("city"),
      },
    };

    const xhr = new XMLHttpRequest();
    xhr.open("POST", "https://jsonplaceholder.typicode.com/users/");
    xhr.setRequestHeader("Content-type", "application/json; charset=UTF-8");
    xhr.send(JSON.stringify(postObject));

    xhr.onload = () => {
      if (xhr.status === 201) {
        const storedUser = JSON.parse(localStorage.getItem("users")) || [];
        storedUser.unshift(postObject);
        localStorage.setItem("users", JSON.stringify(storedUser));
        displayData();
      } else {
        console.error("Error posting data:", xhr.statusText);
      }
    };
  });
}
