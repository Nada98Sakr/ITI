import React, {useState, useEffect} from "react";
import './home.css'
import Artist from "../Artist/Artist";

const Home = () => {
    const API_URL = "http://localhost:3500/artists";
    const [artists, setArtists] = useState([]);

    const getArtists = async () => {
        try {
            const response = await fetch(API_URL);
            const data = await response.json();
            setArtists(data);
        } catch (error) {
            console.log("Error in getting artists:", error);
        }
    }

    useEffect(() => {
        getArtists();
    }, []);

    return (
        <div>
            <div className="artists">
                {artists.map((artist) => (
                    <Artist artist={artist} key={artist.id} />
                ))}
            </div>
        </div>
    );
}

export default Home;