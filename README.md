# 🛒 Tesco Kart Wii (The Ultimate Supermarket Racing Memorial)

Welcome to **Tesco Kart Wii**, a community-driven open-source racing game built from scratch as a standalone Homebrew title for the Nintendo Wii. This project is dedicated to celebrating 30 years of Tesco's history in Central Europe. Since Tesco is officially leaving the Slovak and Czech markets, we are building the ultimate digital memorial – a chaotic, fun-filled independent racing game where shopping carts replace karts!

This is a standalone game concept and open-source project managed directly via mobile. **We are actively looking for C++ homebrew developers, 3D modelers, and UI designers to help bring this vision to life using devkitPro!**

---

## 🎮 Game Concept & Features

Imagine drifting through supermarket aisles, throwing expired products at your opponents, and triggering checkout sirens to disorient the leader. That is **Tesco Kart Wii**.

### 🏁 Featured Track: Tesco Nové Mesto nad Váhom (Slovakia)
Our premier racing circuit is modeled after the iconic hypermarket on Trenčianska Street in Nové Mesto nad Váhom.
*   **Sector 1 (The Parking Lot):** The starting grid. Dodge parked cars and shopping cart shelters to build your mini-turbo.
*   **Sector 2 (The Entrance Hall):** Crash through the automatic sliding doors, drift sharply around the Post Office (Pošta 3) and local pharmacy.
*   **Sector 3 (The Aisle of Doom):** High-speed straight line between shelves. Run over bright yellow "AKCIA" (SALE) pads for a massive speed boost, but watch out for falling cereal boxes.
*   **Sector 4 (The Self-Checkout Chicane):** A tight S-curve right before the exit. You must pass through green open checkouts; hitting a closed red one stops you dead in your tracks.
*   **The Secret Loading Dock:** A risky shortcut through the employee warehouse with a ramp jumping over delivery trucks.

---

## 👥 The Character Roster

Our driver lineup features official corporate mascots and beloved local campaign figures, all hardcoded with unique stats (Speed, Acceleration, Handling, Weight):

1.  **Henio (Eksperci Tesco):** The legendary Polish dad in the checkered sweater. Heavyweight brawler with high top speed but slow handling.
2.  **Krysia (Eksperci Tesco):** Henio’s pragmatic wife in her apron. Lightweight, agile, and has the best acceleration on the grid.
3.  **Tadeusz (Eksperci Tesco):** The smart analyst with black hair and glasses. His kart is equipped with a laser barcode scanner.
4.  **Bogusz (Eksperci Tesco):** The long-haired blonde guy in the orange shirt. Total slacker vibe, built for constant drifting.
5.  **Mr. Clubcard Flyer (Mascot):** A living, sentient paper leaflet with eyes, arms, and a giant `-50%` discount printed on his chest. Can flatten himself into a slippery trap on the road.
6.  **Fero Joke (Special Slovak Guest):** The famous comedian in his signature blue Tesco apron and wig. Shoots Instagram stories while driving and confuses opponents with his iconic "Maja" catchphrases.

---

## 🛠️ Tech Stack & How to Contribute (We Need You!)

This is a **100% independent Homebrew game** compiled into a standalone `.dol`/`.elf` executable for the Nintendo Wii. It does not require any other retail games to run.

*   **Language:** C++
*   **Libraries:** `GRRLIB` (for 2D/3D rendering), `libogc`, `wiiuse`
*   **Toolchain:** devkitPro (devkitPPC)

### 📂 We actively need:
*   **C++ Developers:** To implement physics, item boxes, and multiplayer logic into our `main.cpp` loop.
*   **3D Modelers:** To build low-poly shopping carts, Tesco shelves, and low-poly characters compatible with Wii hardware hardware constraints (Max ~1500 polygons).
*   **Texture Artists:** To create 256x256 `.tpl` textures for local store signs, product boxes, and UI elements.

### 📲 How to help right now:
1.  **Fork** this repository.
2.  Check the **Issues** tab for open tasks (modeling carts, creating UI textures, remixing the Tesco Radio soundtrack into a 16-bit racing theme).
3.  Submit a **Pull Request** with your code, models, or textures!

---

*Disclaimer: This is a non-profit, fan-made parody project created for historical preservation and memorial purposes. All trademarks belong to their respective owners.*
# Tesco-Kart-Wii
