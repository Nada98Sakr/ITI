import { BrowserRouter, Route, Routes } from "react-router-dom";
import Header from "./components/header";
import Home from "./components/home";
import Details from "./components/details";
import Profile from "./components/profile";
import Error from "./components/error";
import "./App.css";

function App() {
    return (
        <div className="App">
            <BrowserRouter>
                <div className="header">
                    <Header />
                </div>
                <Routes>
                    <Route path="/" element={<Home />} />
                    <Route path="/home" element={<Home />} />
                    <Route path="/students/:id" element={<Details />} />
                    <Route path="/profile" element={<Profile />} />
                    <Route path="*" element={<Error />} />
                </Routes>
            </BrowserRouter>
        </div>
    );
}

export default App;
