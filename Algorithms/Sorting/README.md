# Calendly Clone - Complete Files

## File Structure:
```
calendly-clone/
├── index.html          (Landing Page)
├── login.html          (Login Page)
├── dashboard.html      (User Dashboard)
├── styles.css          (Landing Page Styles)
├── login-styles.css    (Login Page Styles)
└── dashboard-styles.css (Dashboard Styles)
```

---

## FILE 1: index.html

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calendly - Easy Scheduling Ahead</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <!-- Header -->
    <header class="header">
        <div class="container">
            <div class="header-content">
                <div class="logo">
                    <svg viewBox="0 0 24 24" fill="currentColor">
                        <circle cx="12" cy="12" r="10"/>
                        <path d="M12 6v6l4 2" stroke="white" stroke-width="2" fill="none"/>
                    </svg>
                    <span>Calendly</span>
                </div>
                
                <nav class="nav-menu">
                    <div class="nav-item">
                        Product <span class="arrow">▼</span>
                    </div>
                    <div class="nav-item">
                        Solutions <span class="arrow">▼</span>
                    </div>
                    <div class="nav-item">
                        Resources <span class="arrow">▼</span>
                    </div>
                    <a href="#" class="nav-item">Pricing</a>
                </nav>
                
                <div class="header-actions">
                    <div class="language">
                        🌐 English <span class="arrow">▼</span>
                    </div>
                    <a href="#" class="talk-sales">Talk to sales</a>
                    <a href="login.html" class="btn-login">Log In</a>
                    <a href="login.html" class="btn-signup">Get started</a>
                </div>
            </div>
        </div>
    </header>

    <!-- Hero Section -->
    <section class="hero">
        <div class="container">
            <div class="hero-grid">
                <div class="hero-left">
                    <h1 class="hero-title">Easy scheduling ahead</h1>
                    <p class="hero-subtitle">Join 20 million professionals who easily book meetings with the #1 scheduling tool.</p>
                    
                    <div class="cta-buttons">
                        <a href="login.html" class="btn-google">
                            <svg viewBox="0 0 24 24" width="20" height="20">
                                <path fill="#4285F4" d="M22.56 12.25c0-.78-.07-1.53-.2-2.25H12v4.26h5.92c-.26 1.37-1.04 2.53-2.21 3.31v2.77h3.57c2.08-1.92 3.28-4.74 3.28-8.09z"/>
                                <path fill="#34A853" d="M12 23c2.97 0 5.46-.98 7.28-2.66l-3.57-2.77c-.98.66-2.23 1.06-3.71 1.06-2.86 0-5.29-1.93-6.16-4.53H2.18v2.84C3.99 20.53 7.7 23 12 23z"/>
                                <path fill="#FBBC05" d="M5.84 14.09c-.22-.66-.35-1.36-.35-2.09s.13-1.43.35-2.09V7.07H2.18C1.43 8.55 1 10.22 1 12s.43 3.45 1.18 4.93l2.85-2.22.81-.62z"/>
                                <path fill="#EA4335" d="M12 5.38c1.62 0 3.06.56 4.21 1.64l3.15-3.15C17.45 2.09 14.97 1 12 1 7.7 1 3.99 3.47 2.18 7.07l3.66 2.84c.87-2.6 3.3-4.53 6.16-4.53z"/>
                            </svg>
                            Sign up with Google
                        </a>
                        
                        <a href="login.html" class="btn-microsoft">
                            <svg viewBox="0 0 24 24" width="20" height="20">
                                <path fill="#f25022" d="M1 1h10v10H1z"/>
                                <path fill="#00a4ef" d="M13 1h10v10H13z"/>
                                <path fill="#7fba00" d="M1 13h10v10H1z"/>
                                <path fill="#ffb900" d="M13 13h10v10H13z"/>
                            </svg>
                            Sign up with Microsoft
                        </a>
                    </div>
                    
                    <p class="terms">By proceeding, you confirm that you have read and agree to Calendly's Terms of Use and Privacy Notice.</p>
                </div>
                
                <div class="hero-right">
                    <div class="demo-card">
                        <div class="card-gradient blue"></div>
                        <div class="demo-content">
                            <h3>Share your booking page</h3>
                            
                            <div class="booking-preview">
                                <div class="profile-section">
                                    <div class="profile-icon">
                                        <svg viewBox="0 0 40 40" fill="#0069FF">
                                            <path d="M20 0L0 10v20l20 10 20-10V10z"/>
                                        </svg>
                                        <span>ACME Inc.</span>
                                    </div>
                                    <div class="profile-info">
                                        <img src="https://via.placeholder.com/50" alt="Profile">
                                        <div>
                                            <p class="name">Fatima Sy</p>
                                            <p class="event-type">Client Check-in</p>
                                        </div>
                                    </div>
                                    <div class="event-details">
                                        <div class="detail">🕐 30 min</div>
                                        <div class="detail">📹 Zoom</div>
                                    </div>
                                </div>
                                
                                <div class="calendar-section">
                                    <h4>Select a Date & Time</h4>
                                    <div class="calendar-header">
                                        <button class="nav-btn">‹</button>
                                        <span class="month">July 2024</span>
                                        <button class="nav-btn">›</button>
                                    </div>
                                    <div class="calendar-grid">
                                        <div class="day-label">SUN</div>
                                        <div class="day-label">MON</div>
                                        <div class="day-label">TUE</div>
                                        <div class="day-label">WED</div>
                                        <div class="day-label">THU</div>
                                        <div class="day-label">FRI</div>
                                        <div class="day-label">SAT</div>
                                        
                                        <div class="day disabled">30</div>
                                        <div class="day">1</div>
                                        <div class="day">2</div>
                                        <div class="day">3</div>
                                        <div class="day">4</div>
                                        <div class="day">5</div>
                                        <div class="day">6</div>
                                        <div class="day">7</div>
                                        <div class="day">8</div>
                                        <div class="day">9</div>
                                        <div class="day">10</div>
                                        <div class="day">11</div>
                                        <div class="day">12</div>
                                        <div class="day">13</div>
                                        <div class="day">14</div>
                                        <div class="day">15</div>
                                        <div class="day available">16</div>
                                        <div class="day available">17</div>
                                        <div class="day">18</div>
                                        <div class="day available">19</div>
                                        <div class="day">20</div>
                                        <div class="day">21</div>
                                        <div class="day selected">22</div>
                                        <div class="day available">23</div>
                                        <div class="day available">24</div>
                                        <div class="day available">25</div>
                                        <div class="day">26</div>
                                        <div class="day">27</div>
                                    </div>
                                    
                                    <div class="timezone">
                                        <span>⏰ Eastern time - US & Canada</span>
                                    </div>
                                </div>
                                
                                <div class="time-section">
                                    <p class="selected-date">Monday, July 22</p>
                                    <div class="time-slots">
                                        <button class="time-slot">10:00am</button>
                                        <button class="time-slot selected">11:00am</button>
                                        <button class="time-slot">1:00pm</button>
                                        <button class="time-slot">2:30pm</button>
                                        <button class="time-slot">4:00pm</button>
                                    </div>
                                    <button class="btn-confirm">Confirm</button>
                                </div>
                            </div>
                        </div>
                        <div class="card-gradient purple"></div>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Trust Section -->
    <section class="trust">
        <div class="container">
            <p class="trust-text">Trusted by more than <strong>100,000</strong> of the world's leading organizations</p>
            <div class="logos">
                <div class="logo-item">INDIANA UNIVERSITY</div>
                <div class="logo-item">DOORDASH</div>
                <div class="logo-item">LYFT</div>
                <div class="logo-item">COMPASS</div>
                <div class="logo-item">L'OREAL</div>
                <div class="logo-item">ZENDESK</div>
                <div class="logo-item">DROPBOX</div>
            </div>
        </div>
    </section>

    <!-- Simple Section -->
    <section class="simple">
        <div class="container">
            <h2 class="section-title">Calendly makes scheduling simple</h2>
            <p class="section-subtitle">Calendly's easy enough for individual users, and powerful enough to meet the needs of enterprise organizations — including 86% of the Fortune 500 companies.</p>
            <a href="login.html" class="btn-primary">Sign up for free</a>
        </div>
    </section>

    <!-- Chat Widget -->
    <div class="chat-widget">
        <svg viewBox="0 0 24 24" fill="white" width="24" height="24">
            <path d="M20 2H4c-1.1 0-2 .9-2 2v18l4-4h14c1.1 0 2-.9 2-2V4c0-1.1-.9-2-2-2z"/>
        </svg>
    </div>
</body>
</html>
```

---

## FILE 2: styles.css

```css
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body {
    font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif;
    color: #0b2540;
    background: #fff;
    overflow-x: hidden;
}

.container {
    max-width: 1400px;
    margin: 0 auto;
    padding: 0 40px;
}

/* Header */
.header {
    background: #f8f9fb;
    padding: 16px 0;
    position: sticky;
    top: 0;
    z-index: 1000;
    border-bottom: 1px solid #e1e4e8;
}

.header-content {
    display: flex;
    align-items: center;
    justify-content: space-between;
}

.logo {
    display: flex;
    align-items: center;
    gap: 8px;
    font-size: 24px;
    font-weight: 700;
    color: #0069ff;
}

.logo svg {
    width: 32px;
    height: 32px;
}

.nav-menu {
    display: flex;
    gap: 32px;
    align-items: center;
}

.nav-item {
    color: #0b2540;
    font-size: 16px;
    font-weight: 500;
    cursor: pointer;
    text-decoration: none;
    transition: color 0.2s;
}

.nav-item:hover {
    color: #0069ff;
}

.arrow {
    font-size: 12px;
    margin-left: 4px;
}

.header-actions {
    display: flex;
    align-items: center;
    gap: 16px;
}

.language {
    color: #6b7684;
    font-size: 14px;
    cursor: pointer;
    display: flex;
    align-items: center;
    gap: 4px;
}

.talk-sales {
    color: #0b2540;
    text-decoration: none;
    font-size: 14px;
    font-weight: 500;
}

.btn-login {
    color: #0b2540;
    text-decoration: none;
    font-size: 16px;
    font-weight: 500;
    padding: 10px 20px;
}

.btn-signup {
    background: #0069ff;
    color: white;
    text-decoration: none;
    padding: 12px 24px;
    border-radius: 8px;
    font-size: 16px;
    font-weight: 600;
    transition: background 0.2s;
}

.btn-signup:hover {
    background: #0052cc;
}

/* Hero Section */
.hero {
    padding: 80px 0;
    background: linear-gradient(180deg, #f8f9fb 0%, #fff 100%);
}

.hero-grid {
    display: grid;
    grid-template-columns: 1fr 1fr;
    gap: 80px;
    align-items: center;
}

.hero-title {
    font-size: 56px;
    line-height: 1.1;
    font-weight: 700;
    color: #0b2540;
    margin-bottom: 24px;
}

.hero-subtitle {
    font-size: 20px;
    line-height: 1.6;
    color: #6b7684;
    margin-bottom: 40px;
}

.cta-buttons {
    display: flex;
    flex-direction: column;
    gap: 16px;
    margin-bottom: 24px;
}

.btn-google,
.btn-microsoft {
    display: flex;
    align-items: center;
    justify-content: center;
    gap: 12px;
    padding: 16px 24px;
    border-radius: 8px;
    font-size: 16px;
    font-weight: 600;
    text-decoration: none;
    transition: all 0.2s;
    border: 2px solid #e1e4e8;
}

.btn-google {
    background: #0069ff;
    color: white;
    border-color: #0069ff;
}

.btn-google:hover {
    background: #0052cc;
    border-color: #0052cc;
}

.btn-microsoft {
    background: #0b2540;
    color: white;
    border-color: #0b2540;
}

.btn-microsoft:hover {
    background: #081a2e;
}

.terms {
    font-size: 13px;
    color: #6b7684;
    line-height: 1.5;
}

/* Demo Card */
.demo-card {
    position: relative;
    background: white;
    border-radius: 16px;
    box-shadow: 0 20px 60px rgba(0, 0, 0, 0.1);
    overflow: hidden;
}

.card-gradient {
    position: absolute;
    height: 80px;
    width: 100%;
}

.card-gradient.blue {
    top: 0;
    background: linear-gradient(135deg, #0069ff 0%, #00a3ff 100%);
    clip-path: polygon(0 0, 100% 0, 100% 50%, 0 100%);
}

.card-gradient.purple {
    bottom: 0;
    right: 0;
    width: 200px;
    height: 200px;
    background: linear-gradient(135deg, #c454ff 0%, #ff54a8 100%);
    clip-path: polygon(100% 0, 100% 100%, 0 100%);
}

.demo-content {
    position: relative;
    padding: 32px;
}

.demo-content h3 {
    font-size: 24px;
    color: #0b2540;
    margin-bottom: 24px;
}

.booking-preview {
    display: grid;
    grid-template-columns: 1fr 1fr 200px;
    gap: 20px;
    background: #f8f9fb;
    padding: 24px;
    border-radius: 12px;
}

.profile-section {
    display: flex;
    flex-direction: column;
    gap: 16px;
}

.profile-icon {
    display: flex;
    align-items: center;
    gap: 8px;
    font-size: 14px;
    font-weight: 600;
}

.profile-icon svg {
    width: 24px;
    height: 24px;
}

.profile-info {
    display: flex;
    gap: 12px;
    align-items: center;
}

.profile-info img {
    width: 50px;
    height: 50px;
    border-radius: 50%;
}

.name {
    font-size: 14px;
    color: #6b7684;
}

.event-type {
    font-size: 18px;
    font-weight: 600;
    color: #0b2540;
}

.event-details {
    display: flex;
    flex-direction: column;
    gap: 8px;
}

.detail {
    font-size: 14px;
    color: #6b7684;
}

.calendar-section h4 {
    font-size: 16px;
    color: #0b2540;
    margin-bottom: 16px;
}

.calendar-header {
    display: flex;
    justify-content: space-between;
    align-items: center;
    margin-bottom: 16px;
}

.nav-btn {
    background: none;
    border: none;
    font-size: 20px;
    cursor: pointer;
    color: #6b7684;
}

.month {
    font-size: 14px;
    font-weight: 600;
    color: #0b2540;
}

.calendar-grid {
    display: grid;
    grid-template-columns: repeat(7, 1fr);
    gap: 4px;
    margin-bottom: 16px;
}

.day-label {
    font-size: 11px;
    color: #6b7684;
    text-align: center;
    padding: 4px;
}

.day {
    aspect-ratio: 1;
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 13px;
    border-radius: 4px;
    cursor: pointer;
    color: #0b2540;
}

.day.disabled {
    color: #c4c9d0;
}

.day.available {
    color: #0069ff;
    font-weight: 600;
}

.day.selected {
    background: #0069ff;
    color: white;
    font-weight: 600;
}

.timezone {
    font-size: 12px;
    color: #6b7684;
    padding: 8px;
    background: white;
    border-radius: 6px;
    text-align: center;
}

.time-section {
    display: flex;
    flex-direction: column;
    gap: 12px;
}

.selected-date {
    font-size: 14px;
    font-weight: 600;
    color: #0b2540;
}

.time-slots {
    display: flex;
    flex-direction: column;
    gap: 8px;
}

.time-slot {
    padding: 12px;
    border: 2px solid #e1e4e8;
    background: white;
    border-radius: 6px;
    font-size: 14px;
    font-weight: 600;
    color: #0069ff;
    cursor: pointer;
    transition: all 0.2s;
}

.time-slot:hover {
    border-color: #0069ff;
}

.time-slot.selected {
    background: #2c3e50;
    color: white;
    border-color: #2c3e50;
}

.btn-confirm {
    padding: 12px;
    background: #0069ff;
    color: white;
    border: none;
    border-radius: 6px;
    font-size: 14px;
    font-weight: 600;
    cursor: pointer;
    transition: background 0.2s;
}

.btn-confirm:hover {
    background: #0052cc;
}

/* Trust Section */
.trust {
    padding: 60px 0;
    background: white;
    border-top: 1px solid #e1e4e8;
}

.trust-text {
    text-align: center;
    font-size: 18px;
    color: #6b7684;
    margin-bottom: 40px;
}

.logos {
    display: flex;
    justify-content: space-between;
    align-items: center;
    flex-wrap: wrap;
    gap: 40px;
}

.logo-item {
    font-size: 16px;
    font-weight: 700;
    color: #0b2540;
    opacity: 0.6;
}

/* Simple Section */
.simple {
    padding: 100px 0;
    text-align: center;
    background: #f8f9fb;
}

.section-title {
    font-size: 48px;
    font-weight: 700;
    color: #0b2540;
    margin-bottom: 24px;
}

.section-subtitle {
    font-size: 20px;
    color: #6b7684;
    line-height: 1.6;
    max-width: 900px;
    margin: 0 auto 40px;
}

.btn-primary {
    display: inline-block;
    background: #0069ff;
    color: white;
    padding: 16px 32px;
    border-radius: 8px;
    font-size: 18px;
    font-weight: 600;
    text-decoration: none;
    transition: background 0.2s;
}

.btn-primary:hover {
    background: #0052cc;
}

/* Chat Widget */
.chat-widget {
    position: fixed;
    bottom: 24px;
    right: 24px;
    width: 56px;
    height: 56px;
    background: #0069ff;
    border-radius: 50%;
    display: flex;
    align-items: center;
    justify-content: center;
    cursor: pointer;
    box-shadow: 0 4px 20px rgba(0, 105, 255, 0.4);
    transition: transform 0.2s;
}

.chat-widget:hover {
    transform: scale(1.1);
}

/* Responsive */
@media (max-width: 1024px) {
    .hero-grid {
        grid-template-columns: 1fr;
        gap: 60px;
    }
    
    .booking-preview {
        grid-template-columns: 1fr;
    }
    
    .nav-menu {
        display: none;
    }
}

@media (max-width: 768px) {
    .container {
        padding: 0 20px;
    }
    
    .hero-title {
        font-size: 40px;
    }
    
    .section-title {
        font-size: 36px;
    }
    
    .logos {
        justify-content: center;
    }
}
```

---

## FILE 3: login.html

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Log in to Calendly</title>
    <link rel="stylesheet" href="login-styles.css">
</head>
<body>
    <div class="login-container">
        <div class="login-box">
            <div class="logo">
                <svg viewBox="0 0 24 24" fill="currentColor">
                    <circle cx="12" cy="12" r="10"/>
                    <path d="M12 6v6l4 2" stroke="white" stroke-width="2" fill="none"/>
                </svg>
                <span>Calendly</span>
            </div>
            
            <h1>Welcome back</h1>
            <p class="subtitle">Log in to your Calendly account</p>
            
            <div class="social-buttons">
                <a href="dashboard.html" class="btn-social">
                    <svg viewBox="0 0 24 24" width="20" height="20">
                        <path fill="#4285F4" d="M22.56 12.25c0-.78-.07-1.53-.2-2.25H12v4.26h5.92c-.26 1.37-1.04 2.53-2.21 3.31v2.77h3.57c2.08-1.92 3.28-4.74 3.28-8.09z"/>
                        <path fill="#34A853" d="M12 23c2.97 0 5.46-.98 7.28-2.66l-3.57-2.77c-.98.66-2.23 1.06-3.71 1.06-2.86 0-5.29-1.93-6.16-4.53H2.18v2.84C3.99 20.53 7.7 23 12 23z"/>
                        <path fill="#FBBC05" d="M5.84 14.09c-.22-.66-.35-1.36-.35-2.09s.13-1.43.35-2.09V7.07H2.18C1.43 8.55 1 10.22 1 12s.43 3.45 1.18 4.93l2.85-2.22.81-.62z"/>
                        <path fill="#EA4335" d="M12 5.38c1.62 0 3.06.56 4.21 1.64l3.15-3.15C17.45 2.09 14.97 1 12 1 7.7 1 3.99 3.47 2.18 7.07l3.66 2.84c.87-2.6 3.3-4.53 6.16-4.53z"/>
                    </svg>
                    Log in with Google
                </a>
                
                <a href="dashboard.html" class="btn-social">
                    <svg viewBox="0 0 24 24" width="20" height="20">
                        <path fill="#f25022" d="M1 1h10v10H1z"/>
                        <path fill="#00a4ef" d="M13 1h10v10H13z"/>
                        <path fill="#7fba00" d="M1 13h10v10H1z"/>
                        <path fill="#ffb900" d="M13 13h10v10H13z"/>
                    </svg>
                    Log in with Microsoft
                </a>
            </div>
            
            <div class="divider">
                <span>OR</span>
            </div>
            
            <form class="login-form">
                <div class="form-group">
                    <label for="email">Email Address</label>
                    <input type="email" id="email" placeholder="Enter your email" required>
                </div>
                
                <div class="form-group">
                    <label for="password">Password</label>
                    <input type="password" id="password" placeholder="Enter your password" required>
                </div>
                
                <a href="#" class="forgot-password">Forgot password?</a>
                
                <a href="dashboard.html" class="btn-submit">Log In</a>
            </form>
            
            <p class="signup-link">Don't have an account? <a href="#">Sign up</a></p>
        </div>
        
        <a href="index.html" class="back-home">← Back to home</a>
    </div>
</body>
</html>
```

---

## FILE 4: login-styles.css

```css
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body {
    font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif;
    background: linear-gradient(135deg, #667eea 0%, #764ba2 50%, #f093fb 100%);
    min-height: 100vh;
    display: flex;
    align-items: center;
    justify-content: center;
    padding: 20px;
}

.login-container {
    width: 100%;
    max-width: 480px;
    position: relative;
}

.login-box {
    background: white;
    border-radius: 12px;
    padding: 48px;
    box-shadow: 0 20px 60px rgba(0, 0, 0, 0.3);
}

.logo {
    display: flex;
    align-items: center;
    justify-content: center;
    gap: 8px;
    font-size: 24px;
    font-weight: 700;
    color: #0069ff;
    margin-bottom: 32px;
}

.logo svg {
    width: 32px;
    height: 32px;
}

h1 {
    font-size: 32px;
    color: #0b2540;
    text-align: center;
    margin-bottom: 8px;
}

.subtitle {
    font-size: 16px;
    color: #6b7684;
    text-align: center;
    margin-bottom: 32px;
}

.social-buttons {
    display: flex;
    flex-direction: column;
    gap: 12px;
}

.btn-social {
    display: flex;
    align-items: center;
    justify-content: center;
    gap: 12px;
    padding: 14px 24px;
    border: 2px solid #e1e4e8;
    border-radius: 8px;
    background: white;
    color: #0b2540;
    font-size: 16px;
    font-weight: 600;
    text-decoration: none;
    transition: all 0.2s;
}

.btn-social:hover {
    border-color: #0069ff;
    background: #f8f9fb;
}

.divider {
    display: flex;
    align-items: center;
    text-align: center;
    margin: 32px 0;
    color: #6b7684;
}

.divider::before,
.divider::after {
    content: '';
    flex: 1;
    border-bottom: 1px solid #e1e4e8;
}

.divider span {
    padding: 0 16px;
    font-size: 14px;
    font-weight: 600;
}

.login-form {
    display: flex;
    flex-direction: column;
    gap: 20px;
}

.form-group {
    display: flex;
    flex-direction: column;
    gap: 8px;
}

label {
    font-size: 14px;
    font-weight: 600;
    color: #0b2540;
}

input {
    padding: 14px 16px;
    border: 2px solid #e1e4e8;
    border-radius: 8px;
    font-size: 16px;
    color: #0b2540;
    transition: border-color 0.2s;
}

input:focus {
    outline: none;
    border-color: #0069ff;
}

.forgot-password {
    text-align: right;
    font-size: 14px;
    color: #0069ff;
    text-decoration: none;
    font-weight: 500;
}

.forgot-password:hover {
    text-decoration: underline;
}

.btn-submit {
    padding: 14px 24px;
    background: #0069ff;
    color: white;
    border: none;
    border-radius: 8px;
    font-size: 16px;
    font-weight: 600;
    cursor: pointer;
    transition: background 0.2s;
    text-align: center;
    text-decoration: none;
    display: block;
}

.btn-submit:hover {
    background: #0052cc;
}

.signup-link {
    text-align: center;
    font-size: 14px;
    color: #6b7684;
    margin-top: 24px;
}

.signup-link a {
    color: #0069ff;
    text-decoration: none;
    font-weight: 600;
}

.signup-link a:hover {
    text-decoration: underline;
}

.back-home {
    display: inline-block;
    margin-top: 24px;
    color: white;
    text-decoration: none;
    font-size: 14px;
    font-weight: 600;
    transition: opacity 0.2s;
}

.back-home:hover {
    opacity: 0.8;
}

@media (max-width: 768px) {
    .login-box {
        padding: 32px 24px;
    }
    
    h1 {
        font-size: 28px;
    }
}
```

---

## FILE 5: dashboard.html

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Scheduling - Calendly</title>
    <link rel="stylesheet" href="dashboard-styles.css">
</head>
<body>
    <!-- Sidebar -->
    <aside class="sidebar">
        <div class="sidebar-header">
            <div class="logo">
                <svg viewBox="0 0 24 24" fill="currentColor">
                    <circle cx="12" cy="12" r="10"/>
                    <path d="M12 6v6l4 2" stroke="white" stroke-width="2" fill="none"/>
                </svg>
                <span>Calendly</span>
            </div>
            <button class="collapse-btn">«</button>
        </div>
        
        <button class="btn-create">
            + Create
        </button>
        
        <nav class="sidebar-nav">
            <a href="#" class="nav-item active">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M3.9 12c0-1.71 1.39-3.1 3.1-3.1h4V7H7c-2.76 0-5 2.24-5 5s2.24 5 5 5h4v-1.9H7c-1.71 0-3.1-1.39-3.1-3.1zM8 13h8v-2H8v2zm9-6h-4v1.9h4c1.71 0 3.1 1.39 3.1 3.1s-1.39 3.1-3.1 3.1h-4V17h4c2.76 0 5-2.24 5-5s-2.24-5-5-5z"/>
                </svg>
                Scheduling
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M19 3h-1V1h-2v2H8V1H6v2H5c-1.11 0-1.99.9-1.99 2L3 19c0 1.1.89 2 2 2h14c1.1 0 2-.9 2-2V5c0-1.1-.9-2-2-2zm0 16H5V8h14v11z"/>
                </svg>
                Meetings
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M11.99 2C6.47 2 2 6.48 2 12s4.47 10 9.99 10C17.52 22 22 17.52 22 12S17.52 2 11.99 2zM12 20c-4.42 0-8-3.58-8-8s3.58-8 8-8 8 3.58 8 8-3.58 8-8 8zm.5-13H11v6l5.25 3.15.75-1.23-4.5-2.67z"/>
                </svg>
                Availability
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M16 11c1.66 0 2.99-1.34 2.99-3S17.66 5 16 5c-1.66 0-3 1.34-3 3s1.34 3 3 3zm-8 0c1.66 0 2.99-1.34 2.99-3S9.66 5 8 5C6.34 5 5 6.34 5 8s1.34 3 3 3zm0 2c-2.33 0-7 1.17-7 3.5V19h14v-2.5c0-2.33-4.67-3.5-7-3.5zm8 0c-.29 0-.62.02-.97.05 1.16.84 1.97 1.97 1.97 3.45V19h6v-2.5c0-2.33-4.67-3.5-7-3.5z"/>
                </svg>
                Contacts
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M4 6h16v2H4zm0 5h16v2H4zm0 5h16v2H4z"/>
                </svg>
                Workflows
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M4 8h4V4H4v4zm6 12h4v-4h-4v4zm-6 0h4v-4H4v4zm0-6h4v-4H4v4zm6 0h4v-4h-4v4zm6-10v4h4V4h-4zm-6 4h4V4h-4v4zm6 6h4v-4h-4v4zm0 6h4v-4h-4v4z"/>
                </svg>
                Integrations & apps
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M12 2l-5.5 9h11L12 2zm0 3.84L13.93 9h-3.87L12 5.84zM17.5 13c-2.49 0-4.5 2.01-4.5 4.5s2.01 4.5 4.5 4.5 4.5-2.01 4.5-4.5-2.01-4.5-4.5-4.5zm0 7c-1.38 0-2.5-1.12-2.5-2.5s1.12-2.5 2.5-2.5 2.5 1.12 2.5 2.5-1.12 2.5-2.5 2.5zM3 21.5h8v-8H3v8zm2-6h4v4H5v-4z"/>
                </svg>
                Routing
            </a>
        </nav>
        
        <div class="sidebar-footer">
            <a href="#" class="nav-item upgrade">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M12 2C6.48 2 2 6.48 2 12s4.48 10 10 10 10-4.48 10-10S17.52 2 12 2zm1 15h-2v-2h2v2zm0-4h-2V7h2v6z"/>
                </svg>
                Upgrade plan
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M3 13h8V3H3v10zm0 8h8v-6H3v6zm10 0h8V11h-8v10zm0-18v6h8V3h-8z"/>
                </svg>
                Analytics
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M12 2C6.48 2 2 6.48 2 12s4.48 10 10 10 10-4.48 10-10S17.52 2 12 2zm0 3c1.66 0 3 1.34 3 3s-1.34 3-3 3-3-1.34-3-3 1.34-3 3-3zm0 14.2c-2.5 0-4.71-1.28-6-3.22.03-1.99 4-3.08 6-3.08 1.99 0 5.97 1.09 6 3.08-1.29 1.94-3.5 3.22-6 3.22z"/>
                </svg>
                Admin center
            </a>
            <a href="#" class="nav-item">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M12 2C6.48 2 2 6.48 2 12s4.48 10 10 10 10-4.48 10-10S17.52 2 12 2zm1 17h-2v-2h2v2zm2.07-7.75l-.9.92C13.45 12.9 13 13.5 13 15h-2v-.5c0-1.1.45-2.1 1.17-2.83l1.24-1.26c.37-.36.59-.86.59-1.41 0-1.1-.9-2-2-2s-2 .9-2 2H8c0-2.21 1.79-4 4-4s4 1.79 4 4c0 .88-.36 1.68-.93 2.25z"/>
                </svg>
                Help
            </a>
        </div>
    </aside>
    
    <!-- Main Content -->
    <main class="main-content">
        <!-- Top Bar -->
        <div class="top-bar">
            <div class="top-left">
                <button class="btn-create-mobile">+ Create</button>
            </div>
            <div class="top-right">
                <button class="icon-btn">
                    <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                        <path d="M12 22c1.1 0 2-.9 2-2h-4c0 1.1.89 2 2 2zm6-6v-5c0-3.07-1.64-5.64-4.5-6.32V4c0-.83-.67-1.5-1.5-1.5s-1.5.67-1.5 1.5v.68C7.63 5.36 6 7.92 6 11v5l-2 2v1h16v-1l-2-2z"/>
                    </svg>
                </button>
                <div class="user-menu">
                    <div class="avatar">S</div>
                    <span class="dropdown-arrow">▼</span>
                </div>
            </div>
        </div>
        
        <!-- Content Area -->
        <div class="content-area">
            <div class="content-header">
                <h1>Scheduling</h1>
                <button class="help-btn">
                    <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                        <path d="M12 2C6.48 2 2 6.48 2 12s4.48 10 10 10 10-4.48 10-10S17.52 2 12 2zm1 17h-2v-2h2v2zm2.07-7.75l-.9.92C13.45 12.9 13 13.5 13 15h-2v-.5c0-1.1.45-2.1 1.17-2.83l1.24-1.26c.37-.36.59-.86.59-1.41 0-1.1-.9-2-2-2s-2 .9-2 2H8c0-2.21 1.79-4 4-4s4 1.79 4 4c0 .88-.36 1.68-.93 2.25z"/>
                    </svg>
                </button>
            </div>
            
            <div class="tabs">
                <button class="tab active">Event types</button>
                <button class="tab">Single-use links</button>
                <button class="tab">Meeting polls</button>
            </div>
            
            <div class="search-bar">
                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                    <path d="M15.5 14h-.79l-.28-.27C15.41 12.59 16 11.11 16 9.5 16 5.91 13.09 3 9.5 3S3 5.91 3 9.5 5.91 16 9.5 16c1.61 0 3.09-.59 4.23-1.57l.27.28v.79l5 4.99L20.49 19l-4.99-5zm-6 0C7.01 14 5 11.99 5 9.5S7.01 5 9.5 5 14 7.01 14 9.5 11.99 14 9.5 14z"/>
                </svg>
                <input type="text" placeholder="Search event types">
            </div>
            
            <!-- Event List -->
            <div class="event-list">
                <div class="user-section">
                    <div class="user-header">
                        <div class="user-info">
                            <div class="avatar large">S</div>
                            <span class="user-name">Sahil More</span>
                        </div>
                        <a href="index.html" class="btn-view-page">
                            <svg viewBox="0 0 24 24" width="16" height="16" fill="currentColor">
                                <path d="M19 19H5V5h7V3H5c-1.11 0-2 .9-2 2v14c0 1.1.89 2 2 2h14c1.1 0 2-.9 2-2v-7h-2v7zM14 3v2h3.59l-9.83 9.83 1.41 1.41L19 6.41V10h2V3h-7z"/>
                            </svg>
                            View landing page
                        </a>
                    </div>
                    
                    <div class="event-card">
                        <div class="event-color purple"></div>
                        <div class="event-content">
                            <div class="event-header-row">
                                <input type="checkbox" class="event-checkbox">
                                <div class="event-info">
                                    <h3>30 Minute Meeting</h3>
                                    <p class="event-meta">30 min • Google Meet • One-on-One</p>
                                    <p class="event-schedule">Weekdays, 9 am - 5 pm</p>
                                </div>
                            </div>
                        </div>
                        <div class="event-actions">
                            <button class="btn-copy">
                                <svg viewBox="0 0 24 24" width="16" height="16" fill="currentColor">
                                    <path d="M16 1H4c-1.1 0-2 .9-2 2v14h2V3h12V1zm3 4H8c-1.1 0-2 .9-2 2v14c0 1.1.9 2 2 2h11c1.1 0 2-.9 2-2V7c0-1.1-.9-2-2-2zm0 16H8V7h11v14z"/>
                                </svg>
                                Copy link
                            </button>
                            <button class="icon-btn">
                                <svg viewBox="0 0 24 24" width="20" height="20" fill="currentColor">
                                    <path d="M12 8c1.1 0 2-.9 2-2s-.9-2-2-2-2 .9-2 2 .9 2 2 2zm0 2c-1.1 0-2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2zm0 6c-1.1 0-2 .9-2 2s.9 2 2 2 2-.9 2-2-.9-2-2-2z"/>
                                </svg>
                            </button>
                        </div>
                    </div>
                </div>
            </div>
        </div>
        
        <!-- Get Started Sidebar -->
        <aside class="get-started-sidebar">
            <button class="close-sidebar">×</button>
            <h2>Get started</h2>
            
            <div class="task-list">
                <div class="task-item">
                    <div class="task-icon">
                        <svg viewBox="0 0 24 24" width="24" height="24" fill="#0069ff">
                            <path d="M12 2C6.48 2 2 6.48 2 12s4.48 10 10 10 10-4.48 10-10S17.52 2 12 2zm-2 15l-5-5 1.41-1.41L10 14.17l7.59-7.59L19 8l-9 9z"/>
                        </svg>
                    </div>
                    <div class="task-content">
                        <h3>Get to know Calendly</h3>
                        <p>1 video</p>
                    </div>
                </div>
                
                <div class="task-item">
                    <div class="task-icon">
                        <svg viewBox="0 0 24 24" width="24" height="24" fill="#0069ff">
                            <path d="M19 3h-4.18C14.4 1.84 13.3 1 12 1c-1.3 0-2.4.84-2.82 2H5c-1.1 0-2 .9-2 2v14c0 1.1.9 2 2 2h14c1.1 0 2-.9 2-2V5c0-1.1-.9-2-2-2zm-7 0c.55 0 1 .45 1 1s-.45 1-1 1-1-.45-1-1 .45-1 1-1zm2 14H7v-2h7v2zm3-4H7v-2h10v2zm0-4H7V7h10v2z"/>
                        </svg>
                    </div>
                    <div class="task-content">
                        <h3>The perfect scheduling setup</h3>
                        <p>2 tasks</p>
                    </div>
                </div>
                
                <div class="task-item">
                    <div class="task-icon">
                        <svg viewBox="0 0 24 24" width="24" height="24" fill="#0069ff">
                            <path d="M20 4H4c-1.1 0-1.99.9-1.99 2L2 18c0 1.1.9 2 2 2h16c1.1 0 2-.9 2-2V6c0-1.1-.9-2-2-2zm0 4l-8 5-8-5V6l8 5 8-5v2z"/>
                        </svg>
                    </div>
                    <div class="task-content">
                        <h3>Automate meeting prep and follow-up</h3>
                        <p>2 tasks</p>
                    </div>
                </div>
                
                <div class="task-item">
                    <div class="task-icon">
                        <svg viewBox="0 0 24 24" width="24" height="24" fill="#0069ff">
                            <path d="M16 11c1.66 0 2.99-1.34 2.99-3S17.66 5 16 5c-1.66 0-3 1.34-3 3s1.34 3 3 3zm-8 0c1.66 0 2.99-1.34 2.99-3S9.66 5 8 5C6.34 5 5 6.34 5 8s1.34 3 3 3zm0 2c-2.33 0-7 1.17-7 3.5V19h14v-2.5c0-2.33-4.67-3.5-7-3.5zm8 0c-.29 0-.62.02-.97.05 1.16.84 1.97 1.97 1.97 3.45V19h6v-2.5c0-2.33-4.67-3.5-7-3.5z"/>
                        </svg>
                    </div>
                    <div class="task-content">
                        <h3>Using Calendly with a team</h3>
                        <p>2 tasks</p>
                    </div>
                </div>
            </div>
            
            <button class="btn-dont-show">Don't show again</button>
        </aside>
    </main>
    
    <!-- Chat Widget -->
    <div class="chat-widget">
        <svg viewBox="0 0 24 24" fill="white" width="24" height="24">
            <path d="M20 2H4c-1.1 0-2 .9-2 2v18l4-4h14c1.1 0 2-.9 2-2V4c0-1.1-.9-2-2-2z"/>
        </svg>
    </div>
</body>
</html>
```

---

## FILE 6: dashboard-styles.css

```css
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

body {
    font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, 'Helvetica Neue', Arial, sans-serif;
    display: flex;
    height: 100vh;
    background: #f8f9fb;
    color: #0b2540;
}

/* Sidebar */
.sidebar {
    width: 260px;
    background: white;
    border-right: 1px solid #e1e4e8;
    display: flex;
    flex-direction: column;
    padding: 20px 16px;
    overflow-y: auto;
}

.sidebar-header {
    display: flex;
    align-items: center;
    justify-content: space-between;
    margin-bottom: 20px;
}

.logo {
    display: flex;
    align-items: center;
    gap: 8px;
    font-size: 20px;
    font-weight: 700;
    color: #0069ff;
}

.logo svg {
    width: 28px;
    height: 28px;
}

.collapse-btn {
    background: none;
    border: none;
    font-size: 20px;
    color: #6b7684;
    cursor: pointer;
    padding: 4px 8px;
}

.btn-create {
    width: 100%;
    padding: 12px 16px;
    background: white;
    border: 2px solid #0069ff;
    border-radius: 8px;
    color: #0069ff;
    font-size: 16px;
    font-weight: 600;
    cursor: pointer;
    margin-bottom: 20px;
    transition: all 0.2s;
}

.btn-create:hover {
    background: #0069ff;
    color: white;
}

.sidebar-nav {
    display: flex;
    flex-direction: column;
    gap: 4px;
    flex: 1;
}

.nav-item {
    display: flex;
    align-items: center;
    gap: 12px;
    padding: 12px 16px;
    border-radius: 8px;
    color: #0b2540;
    text-decoration: none;
    font-size: 15px;
    font-weight: 500;
    transition: background 0.2s;
}

.nav-item:hover {
    background: #f8f9fb;
}

.nav-item.active {
    background: #e8f2ff;
    color: #0069ff;
}

.nav-item.upgrade {
    background: #f0f7ff;
    color: #0069ff;
    border: 1px solid #c5e0ff;
}

.sidebar-footer {
    margin-top: auto;
    padding-top: 20px;
    border-top: 1px solid #e1e4e8;
    display: flex;
    flex-direction: column;
    gap: 4px;
}

/* Main Content */
.main-content {
    flex: 1;
    display: flex;
    flex-direction: column;
    overflow: hidden;
}

.top-bar {
    background: white;
    border-bottom: 1px soli
