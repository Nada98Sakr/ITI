import { BrowserRouter, Route, Routes } from "react-router-dom";
import Home from "./components/Home/home";
import Details from "./components/Details/Details";
import "./App.css";

const App = () => {
    return (
        <div className="App">
            <BrowserRouter>
                <Routes>
                    <Route path="/" element={<Home />} />
                    <Route path="/artists/:id" element={<Details />} />
                </Routes>
            </BrowserRouter>
        </div>
    );
};

export default App;
